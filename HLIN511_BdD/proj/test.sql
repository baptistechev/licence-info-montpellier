/*
Fichier: Creation_GroupeD9.sql
Auteurs:
Adam LEMONNIER 201908914
Baptiste CHEVALIER 21813639
Nom du groupe: D9
*/

/*
SUPRESSION DE LA BASE DE DONNÉES
*/
DROP DATABASE IF EXISTS complexe_sportif;
CREATE DATABASE complexe_sportif;
USE complexe_sportif;

/*
CREATION DE LA BASE DE DONNÉES
*/

DROP TABLE IF EXISTS Joueur;
DROP TABLE IF EXISTS tournoi_equipe;
DROP TABLE IF EXISTS Classement;
DROP TABLE IF EXISTS MatchPoule;
DROP TABLE IF EXISTS Equipe;
DROP TABLE IF EXISTS Poule;
DROP TABLE IF EXISTS Tournoi;
DROP TABLE IF EXISTS Evenement;
DROP TABLE IF EXISTS TypeJeu;
DROP TABLE IF EXISTS Organisateur;
DROP TABLE IF EXISTS LOGERROR;

/*
Création des relations
*/

CREATE TABLE Equipe (
	nom VARCHAR(255) NOT NULL,
	niveauE INT, 
	club VARCHAR(255) NOT NULL,
	CONSTRAINT E_PK PRIMARY KEY(nom)
);

CREATE TABLE Joueur (
	id INT AUTO_INCREMENT NOT NULL,
	nom_equipe VARCHAR(255) DEFAULT NULL,
	nom VARCHAR(255) NOT NULL,
	niveau INT NOT NULL,
	CONSTRAINT J_PK PRIMARY KEY(id),
	CONSTRAINT J_FK FOREIGN KEY (nom_equipe) REFERENCES Equipe (nom)
);

CREATE TABLE TypeJeu (
	id INT AUTO_INCREMENT NOT NULL, 
	description VARCHAR(255) NOT NULL,
	CONSTRAINT T_PK PRIMARY KEY(id)
);

CREATE TABLE Evenement (
	id INT AUTO_INCREMENT NOT NULL,
	lieu VARCHAR(255),
	date DATETIME,
	nbJEquipe INT NOT NULL,
	nom VARCHAR(255) NOT NULL, 
	nbTournoi INT NOT NULL, 
	typeJeu_id INT DEFAULT NULL,
	CONSTRAINT E_PK PRIMARY KEY(id),
	CONSTRAINT E_FK FOREIGN KEY (typeJeu_id) REFERENCES TypeJeu (id)
);

CREATE TABLE Tournoi (
	id INT AUTO_INCREMENT NOT NULL,
	evenement_id INT DEFAULT NULL,
	nom VARCHAR(255) NOT NULL, 
	tour INT NOT NULL,
	CONSTRAINT T_PK PRIMARY KEY(id),
	CONSTRAINT T_FK FOREIGN KEY (evenement_id) REFERENCES Evenement (id)
);

CREATE TABLE tournoi_equipe (
	tournois INT NOT NULL, 
	equipes VARCHAR(255) NOT NULL,
	CONSTRAINT t_PK PRIMARY KEY (tournois, equipes),
	CONSTRAINT t_FK1 FOREIGN KEY (tournois) REFERENCES Tournoi (id),
	CONSTRAINT t_FK2 FOREIGN KEY (equipes) REFERENCES Equipe (nom)
);

CREATE TABLE Poule (
	id INT AUTO_INCREMENT NOT NULL,
	tournoi_id INT DEFAULT NULL, 
	nom VARCHAR(255) NOT NULL, 
	format VARCHAR(255), 
	tour INT NOT NULL,
	CONSTRAINT P_PK PRIMARY KEY(id),
	CONSTRAINT P_FK FOREIGN KEY (tournoi_id) REFERENCES Tournoi (id)
);

CREATE TABLE MatchPoule (
	equipe1 VARCHAR(255) NOT NULL,
	equipe2 VARCHAR(255) NOT NULL,
	poule_id INT NOT NULL,
	score VARCHAR(255),
	terrain VARCHAR(255),
	CONSTRAINT M_PK PRIMARY KEY(equipe1, equipe2, poule_id),
	CONSTRAINT M_FK1 FOREIGN KEY (equipe1) REFERENCES Equipe (nom),
	CONSTRAINT M_FK2 FOREIGN KEY (equipe2) REFERENCES Equipe (nom),
	CONSTRAINT M_FK3 FOREIGN KEY (poule_id) REFERENCES Poule (id)
);

CREATE TABLE Classement (
	poule_id INT NOT NULL, 
	nom_equipe VARCHAR(255) NOT NULL, 
	rang INT,
	CONSTRAINT C_PK PRIMARY KEY(poule_id, nom_equipe),
	CONSTRAINT C_FK1 FOREIGN KEY (poule_id) REFERENCES Poule (id),
	CONSTRAINT C_FK2 FOREIGN KEY (nom_equipe) REFERENCES Equipe (nom)
);

CREATE TABLE Organisateur (
	utilisateur VARCHAR(255) NOT NULL,
	mot_de_pass VARCHAR(255) NOT NULL,
	nom VARCHAR(255) NOT NULL,
	CONSTRAINT O_PK PRIMARY KEY(utilisateur)
);

CREATE TABLE LOGERROR  (
  ID INT(11) AUTO_INCREMENT,
  MESSAGE VARCHAR(255) DEFAULT NULL,
  THETIME TIMESTAMP NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  CONSTRAINT PK_LOGERROR PRIMARY KEY (ID)
);	

/* 
Insertion de tuples dans les relations
*/

INSERT INTO TypeJeu VALUES (1, "Volley");
INSERT INTO Evenement VALUES (1, "Tokyo", STR_TO_DATE('14-07-2020', '%d-%m-%Y'), 2, "FeteNat", 1, 1);
INSERT INTO Tournoi VALUES (1, 1, "Principal", 1);

/* 
Affichage des tuples
*/
SELECT * FROM TypeJeu;
SELECT * FROM Evenement;
SELECT * FROM Tournoi;

/*
Définition de triggers
*/

/*
	Trigger pour verifier le tour d'une poule (a partir du tour du tournoi)
*/

DROP TRIGGER IF EXISTS TOUR_POULE_TOURNOI

DELIMITER $$
CREATE TRIGGER TOUR_POULE_TOURNOI
BEFORE INSERT on Poule
FOR EACH ROW 
BEGIN 
	DECLARE TOUR_TOURNOI INT;
	SET TOUR_TOURNOI = (SELECT tour FROM Tournoi where id=NEW.tournoi_id);

	IF NEW.tour <> TOUR_TOURNOI THEN
		/* Le message ne s'insere pas.... */
        SIGNAL SQLSTATE VALUE '45000' SET MESSAGE_TEXT ='LE TOUR DE LA POULE DOIT ETRE IDENTIQUE AU TOUR DU TOURNOI';
        INSERT INTO LOGERROR(MESSAGE) VALUES ("ERREUR TOUR DE LA POULE DIFFERENT DU TOUR DU TOURNOI");
    END IF; 
END; $$

/*
	Trigger pour verifier que les equipes et la poules qui composent un match sont bien dans le meme tournoi
*/

/*
	Trigger pour verifier que le match n'est pas contitué de 2 fois la même equipe sinon -> error
*/

/*
	Trigger pour verifier que le niveau (joueur ou equipe) est compris entre 0 et 5 sinon -> error
*/


-- DROP TRIGGER IF EXISTS EQUIPE_UNIQUE_TOURNOI;
-- /*DELIMITER $$ ça sert à quoi mdr*/
-- CREATE TRIGGER EQUIPE_UNIQUE_TOURNOI
--     BEFORE INSERT ON tournoi_equipe
--     FOR EACH ROW
-- BEGIN
--     /*
--     DECLARE NOM_EQUIPE VARCHAR(20);
--     SET NOM_EQUIPE = (SELECT nom FROM EQUIPE);

--     IF equipes <> NOM_EQUIPE THEN
--     à poursuivre hehe
--     */

/*
Définition de functions ou procedures
*/

/*
	Fonction qui donne le niveau d'une equipes (regionnal, N2...ect ) en fonction d'une equipe (niveau en nb)
*/

/*
	Fonction qui donne le score total d'une equipes (la somme des points sur les matchs)
*/

/*
	Fonction qui donne la liste des terrains dispo pour un event (en fonction de la date et du type de jeu, terrain interieur/exterieur, taille..Ect)
*/

/*
	Fonction pour calculer le niveau d'une équipe (pas trigger pcq on doit d'abord ajouter les joueurs)
*/



INSERT INTO genre VALUES (3,'policier');
INSERT INTO genre VALUES (4,'action');
INSERT INTO genre VALUES (5,'drame');

INSERT INTO acteur VALUES (1,'Pitt','Brad','Americain');
INSERT INTO acteur VALUES (2,'Defunes','Louis','Francais');

INSERT INTO realisateur VALUES (1,'Besson','Luc','Francais');
INSERT INTO realisateur VALUES (2,'Tarantino','Quentin','Americain');
INSERT INTO realisateur VALUES (3,'Leitch','David','Americain');
INSERT INTO realisateur VALUES (4,'Darrousin','Jean-Pierre','Francais');

INSERT INTO film VALUES (1,'Subway',1985,'France',30000,1,3);
INSERT INTO film VALUES (2,'Deadpool 2',2018,'Etats Unis',8000000,3,2);
INSERT INTO film VALUES (3,'Le pressentiment',2006,'France',50,4,5);
INSERT INTO film VALUES (4,'Le pressentiments',2006,'France',500,4,5);

INSERT INTO jouer VALUES (1,2,30);
INSERT INTO jouer VALUES (2,4,30);
INSERT INTO jouer VALUES (2,2,30);


UPDATE jouer 
SET salaire = salaire+0.2*salaire;

DELETE FROM realisateur
WHERE nom='Tarantino'; 

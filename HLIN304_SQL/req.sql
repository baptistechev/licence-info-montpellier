SELECT nom,prenom,idA FROM acteur,jouer,film,genre
WHERE idA=idActeur AND idF=idFilm AND idG=idGenre AND (description='policier' OR description='humour'); 

SELECT titre FROM film,realisateur
WHERE idR=idRealisateur AND nom='Darrousin'AND annee>2000;

SELECT acteur.nom,acteur.prenom,realisateur.nom,realisateur.prenom FROM acteur,jouer,film,realisateur
WHERE idA=idActeur AND idF=idFilm AND idR=idRealisateur; 

SELECT description FROM film,jouer,acteur,genre
WHERE idA=idActeur AND idF=idFilm AND idG=idGenre AND nom='Pacino' AND prenom='Al';



SELECT COUNT(*) AS nbFilm FROM film;

SELECT annee FROM film
WHERE annee=(SELECT MIN(annee) FROM film);

SELECT AVG(salaire) AS SalaireMoy,MIN(salaire) AS SalaireMin,MAX(salaire) AS SalaireMax FROM jouer;

SELECT AVG(nbspectateurs) AS nbMoy,MIN(nbspectateurs) AS nbMin,MAX(nbspectateurs) AS nbMax FROM film,genre WHERE idG=idGenre AND description='humour';

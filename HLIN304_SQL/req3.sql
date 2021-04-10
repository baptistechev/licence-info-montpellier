select titre from film
where nbspectateurs>(select AVG(nbspectateurs) from film);

select nom,prenom from realisateur,film
where idR=idRealisateur and nbspectateurs>(select AVG(nbspectateurs) from film);

select nom,prenom from acteur,jouer,film where idA=idActeur and idF=idFilm and nbspectateurs=(select max(nbspectateurs) from film);

select nom,prenom from acteur where idA not in (select idActeur from jouer);

select description from genre where idG not in (select idGenre from film);

select nom,prenom from realisateur where idR not in (select idRealisateur from film where annee>2002);

select description from genre,film where idG=idGenre and idG not in (select idGenre from film where nbspectateurs<50000);

select description from genre,film,realisateur where idR=idRealisateur and nationalite='Americain' and idG=idGenre and idG not in (select idGenre from film where nbspectateurs<50000);

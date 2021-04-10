select A1.nom,A1.prenom,F1.titre from acteur A1, jouer J1, film F1 where A1.idA=J1.idActeur and J1.idFilm=F1.idF and nbspectateurs = (select F2.nbspectateurs from film F2, jouer J2 where F2.idF=J2.idFilm and J2.idActeur=J1.idActeur);	

select F1.titre,A1.nom,A1.prenom from film F1,acteur A1,jouer J1 where A1.idA=J1.idActeur and J1.idFilm=F1.idF and J1.salaire = (select max(salaire) from jouer J2 where J2.idActeur=J1.idActeur);

select R1.nom,R1.prenom,F1.titre from realisateur R1,film F1 where R1.idR=F1.idRealisateur and F1.nbspectateurs = (select max(F2.nbspectateurs) from film F2 where F2.idRealisateur=F1.idRealisateur);

select description from genre where idG not in(select idGenre from genre,film where idGenre=idG);

select G1.description from genre G1 where not exists(select G2.idG from genre G2,film where idGenre=idG and G1.idG=G2.idG);

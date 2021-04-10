select count(*) from personne;

select count(*) from personne where prenom is not null;

select count(*) as nbVoiture,nom,prenom from voiture,personne where id=idProprio group by id,nom,prenom;

select sum(prix) as capitale,nom,prenom from personne,voiture where id=idProprio group by id,nom,prenom;

select avg(prix),marque as prixMoyen from voiture group by marque;

select count(*) as nbVoiturePlus20000,nom,prenom from voiture,personne where id=idproprio and prix>20000 group by id,nom,prenom;	

select sum(prix) as capitale,nom,prenom from personne,voiture where id=idProprio group by id,nom,prenom having sum(prix)>50000;

select sum(prix) as capitale,id,annee from personne,voiture where id=idProprio group by id,nom,prenom,annee;

select sum(prix) as capitale,nom,prenom,annee from personne,voiture where id=idProprio group by id,nom,prenom,annee;

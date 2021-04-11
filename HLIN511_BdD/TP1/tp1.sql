Select nom, prenom from abonne where ville='MONTPELLIER';

Select * from exemplaire where code_pret='EMPRUNTABLE';

Select titre, categorie from livre where categorie<>'SCIENCES' and categorie<>'MEDECINE' and categorie<>'LOISIRS' order by categorie, titre;

Select * from emprunt where d_ret_reel is null;

Select num_ex, d_emprunt from emprunt em join Abonne ab on ab.num_ab=em.num_ab where nom='DUPONT' and prenom='JEAN' order by d_emprunt;

Select numero, code_pret, etat from exemplaire em join livre l on em.isbn=l.isbn where titre='LE MUR';

Select numero from exemplaire ex join livre l on ex.isbn=l.isbn where etat='BON' and titre in (Select titre from exemplaire ex join livre l on ex.isbn=l.isbn where numero=4112);

Select titre from livre where isbn not in (Select isbn from exemplaire);

Select titre from livre l where not exists (Select * from exemplaire where isbn=l.isbn);

Select categorie from livre where categorie not in (Select distinct categorie from exemplaire ex join emprunt em on ex.numero=em.num_ex join livre l on l.isbn=ex.isbn);

/* Q9-2
Select distinct categorie from livre l where not exists (Select * from exemplaire ex join emprunt em on ex.numero=em.num_ex where l.isbn=ex.isbn);*/

Select count(*) from emprunt em join abonne ab on ab.num_ab=em.num_ab where nom='RENARD' and prenom='ALBERT' and d_ret_reel is null;

Select min(tarif - tarif*NVL(reduc,0)/100) as tarifMin from abonne;

Select numero from exemplaire ex join emprunt em on ex.numero=em.num_ex where etat='ABIME' and D_RET_REEL is null;

/*13*/
Select mot from mot_clef where mot not in (Select mot from caracterise c join Livre L on c.isbn=L.isbn group by mot);


/*14*/
Select ab.num_ab, nom, categorie, count(*) as NbEmprunt from abonne ab join emprunt em on ab.num_ab=em.num_ab join exemplaire ex on em.num_ex=ex.numero join livre l on ex.isbn=l.isbn group by categorie, ab.num_ab, nom order by categorie;

Select isbn, avg(prix) as prixMoyen from exemplaire group by isbn having count(*) >2;

/* 16 pas suffisant
select isbn from caracterise where isbn<>'0_8_7707_2' group by isbn having count(distinct mot)=(Select count(*) from caracterise where isbn='0_8_7707_2');
*/

Select isbn from caracterise c1 where isbn<>'0_8_7707_2' and not exists(Select * from caracterise M where isbn='0_8_7707_2' and not exists(Select * from caracterise c2 where c1.isbn=c2.isbn and c2.mot=M.mot)) group by isbn;


Select categorie from livre l join exemplaire ex on l.isbn=ex.isbn join emprunt em on ex.numero=em.num_ex join abonne ab on ab.num_ab=em.num_ab group by categorie having count(distinct ab.num_ab)=(Select count(*) from abonne); 

/**Correction 16?*/
/*
select isbn from caracterise group by isbn having count(distinct mot)=(Select count(*) from mot_clef);

Select isbn from caracterise c1 where not exists(Select * from mot_clef M where not exists(Select * from caracterise c2 where c1.isbn=c2.isbn and c2.mot=M.mot));
*/

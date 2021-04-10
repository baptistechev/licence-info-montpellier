select count(*),annee from film group by annee;
select max(nbspectateurs),annee as maxSpec from film group by annee;
select count(*),annee from film group by annee having annee>1990;
select count(*),annee from film where nbspectateurs>1000000 group by annee;

select sum(quantite),numero_operateur from Piece group by numero_operateur;
select nom from operateur,piece where numero=numero_operateur and quantite>500;
select count(*),reference_machine from qualifie_sur group by reference_machine;
select sum(quantite),reference_machine from piece group by reference_machine;
select count(*),numero_operateur from qualifie_sur group by numero_operateur;

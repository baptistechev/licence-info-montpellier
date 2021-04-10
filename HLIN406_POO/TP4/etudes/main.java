package etudes;
import java.time.LocalDate;

public class main{
    public static void main(String[] a){
	Promotion promo = new Promotion(1999);
	promo.inscrire(new Etudiant("Adam",LocalDate.of(2020,04,28),true,CodePays.francophone,18,19,20));
	promo.inscrire(new Etudiant("Anh",LocalDate.of(1943,02,02),true,CodePays.nonFrancophone,12.5f,12.5f,12.5f));
	promo.inscrire(new Etudiant("Sarah",LocalDate.of(1970,02,01),true,CodePays.francais,19,19,19));
	promo.inscrire(new Etudiant("Jean",LocalDate.of(1970,02,01),true,CodePays.francais,12.5f,12.5f,12.5f));
	promo.inscrire(new Etudiant("Michel",LocalDate.of(1970,02,01),true,CodePays.francais,12,18.5f,12.5f));

	promo.afficheResultats();
	/*	for(int i =0;i<promo.nbEtudiant();i++){
	    System.out.println(promo.getEtudiant(i) + " : " + promo.getEtudiant(i).moyenne());
	    }*/
	System.out.println(promo.moyenneGenerale());
	System.out.println(promo.recherche("Adam"));
	System.out.println(promo.recherche("Jean-Bobo"));
	System.out.println(promo.admis());
	System.out.println(promo.nouveauxInscritNonFrancophones());
	System.out.println(promo.majors());
	promo.histo();
	System.out.println(promo.moyennePlusFrequente());
	System.out.println(promo.nbPersonneMoy(13));
    }
}

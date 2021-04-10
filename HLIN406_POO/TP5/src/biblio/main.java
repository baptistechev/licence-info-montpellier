package biblio;

public class main {

	public static void main(String[] args) {
		Notice n1 = new Notice("01", "La fee Carabine", Public.ENFANT);
		Notice n2 = new Notice("02", "”Une langue venue d’ailleur", Public.ADULTE);
		
		Contributeur c1 = new Contributeur("Pennac", "Danniel");
		Contributeur c2 = new Contributeur("Akira", "Mizubayashi");
		
		n1.addContributeur(c1, NatureCtr.AUTEUR);
		
		n2.addContributeur(c2, NatureCtr.AUTEUR);
		n2.addContributeur(c1, NatureCtr.REDACTEURPREFACE);

		//System.out.println(n1.getContributeurs());
		//System.out.println(n2.getContributeurs());
		
		Exemplaire e1 = new Exemplaire(n1,true, Etat.NEUF);
		Exemplaire e2 = new Exemplaire(n1,true, Etat.BON);
		Exemplaire e3 = new Exemplaire(n1,true, Etat.MAUVAIS);
		
		Exemplaire e4 = new Exemplaire(n2,true, Etat.NEUF);
		Exemplaire e5 = new Exemplaire(n2,true, Etat.BON);
		Exemplaire e6 = new Exemplaire(n2,true, Etat.MAUVAIS);
		e3.reparation();
		n1.addExemplaire(e1);
		n1.addExemplaire(e2);
		n1.addExemplaire(e3);
		n1.affiche();
		
		n2.addExemplaire(e4);
		n2.addExemplaire(e5);
		n2.addExemplaire(e6);
		n2.affiche();
		
		System.out.println();
		System.out.println("-------Emprunt--------");
		System.out.println();
		
		Abonne a = new Abonne(01, false);
		Abonne b = new Abonne(2, true);
		a.emprunter(n1);
		a.emprunter(n1);
		a.emprunter(n1);
		
		a.affiche();
		n1.affiche();
		
		System.out.println();
		System.out.println("-------Retour--------");
		System.out.println();
		
		a.rendre(e2);
		
		a.affiche();
		n1.affiche();
		
		System.out.println();
		System.out.println("---------------Abonnée 2 ---------");
		System.out.println();
		
		b.emprunter(n1);
		b.emprunter(n2);
		
		b.affiche();
	}

}

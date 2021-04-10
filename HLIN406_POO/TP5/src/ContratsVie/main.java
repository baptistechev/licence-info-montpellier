package ContratsVie;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Personne A = new Personne("Dupont", "Jean", Sexe.HOMME);
		Personne B = new Personne("Martin", "Genevieve", Sexe.FEMME);
		Personne C = new Personne("LeMaitre", "Boris", Sexe.NON_BINAIRE);
		
		Organisme mairieMont = new Organisme(TOrg.MAIRIE, "Montpellier");
		Organisme tribunalMont = new Organisme(TOrg.TRIBUNAL, "Montpellier");
		
		A.seMarie(B, 2012, mairieMont, "Michel", TCtr.COMMUNAUTE);
		
		System.out.println(A);
		A.afficheContrats();
		System.out.println(B);
		B.afficheContrats();
		
		System.out.println();
		System.out.println("----------Resiliation-----------");
		System.out.println();

		A.resilierCtr(2016);
		
		System.out.println(A);
		A.afficheContrats();
		A.afficheAncienContrats();
		System.out.println(B);
		B.afficheContrats();
		B.afficheAncienContrats();
		
		System.out.println();
		System.out.println("----------PACS Jean-Boris -----------");
		System.out.println();
		
		A.sePacse(C, 2018, tribunalMont);
		
		System.out.println(A);
		A.afficheContrats();
		A.afficheAncienContrats();
		System.out.println(C);
		C.afficheContrats();
		C.afficheAncienContrats();
	}

}

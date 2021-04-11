package pkg2;

import java.util.ArrayList;

import pkg2.FeuilleSalaire.TypePrelevement;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		FeuilleSalaire fs = new FeuilleSalaire("Jean", "Boris", "lalala", 59, TypePrelevement.CRDS, 1397);
		FeuilleSalaire fs2 = new FeuilleSalaire("Maurice", "Joan", "lololo", 96, TypePrelevement.CSG, 1973);
		
//		for (Object o : fs) {
//			System.out.println(o);
//		}
//		
		CollectionFeuillesSalaire CFS = new CollectionFeuillesSalaire();
		CFS.ajouter(fs2);
		CFS.ajouter(fs);
		
		CFS.tri1();
		CFS.print();
		
		ArrayList<FeuilleSalaire> lfs = CFS.getFeuilleSalaire("Maurice");
		ArrayList<String> en = CFS.getEntrepriseContaining("Je");
		
		for (String s : en) {
			System.out.println(s);
		}
		
	}

}

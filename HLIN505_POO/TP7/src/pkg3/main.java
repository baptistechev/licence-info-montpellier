package pkg3;

import java.util.ArrayList;

import pkg3.Etudiant.TypeMod;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Etudiant e1 = new Etudiant("jean", 12, TypeMod.autre);
		Etudiant e2 = new Etudiant("paolo", 89, TypeMod.eCandidat);
		Etudiant e3 = new Etudiant("Philippe", 53, TypeMod.eCandidat);
		Etudiant e4 = new Etudiant("Boris", 89, TypeMod.CampusFrance);
		
		Promotion p = new Promotion();
		p.ajouter(e1);
		p.ajouter(e2);
		p.ajouter(e3);
		p.ajouter(e4);
		
		System.out.println(p.ageMin());
		System.out.println(p.nbEtuVia(TypeMod.eCandidat));
		ArrayList<Etudiant> l =  p.getEtudiantAgeMax();
		for (Etudiant e : l) {
			System.out.println(e);
		}
		
	}

}

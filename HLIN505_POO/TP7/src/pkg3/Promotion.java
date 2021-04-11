package pkg3;

import java.util.ArrayList;
import java.util.stream.Collectors;

import pkg3.Etudiant.TypeMod;

public class Promotion {

	private ArrayList<Etudiant> listeEtudiant;
	
	public Promotion() {
		this.listeEtudiant = new ArrayList<>();
	}
	
	public void ajouter(Etudiant e) {
		this.listeEtudiant.add(e);
	}
	
	public int ageMin() {
		return listeEtudiant
			.stream()
			.filter(e -> e.getMod()==TypeMod.eCandidat)
			.mapToInt(Etudiant::getAge)
			.min()
			.orElse(-1);
	}
	
	public int nbEtuVia(TypeMod mod) {
		return (int) listeEtudiant
				.stream()
				.filter(e -> e.getMod()==mod)
				.count();
	}
	
	public ArrayList<Etudiant> getEtudiantAgeMax(){
		return (ArrayList<Etudiant>) listeEtudiant
				.stream()
				.filter(e -> e.getAge() == listeEtudiant.stream().mapToInt(Etudiant::getAge).max().getAsInt())
				.collect(Collectors.toList());
	}
}

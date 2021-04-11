package pkg2;

import java.util.ArrayList;
import java.util.stream.Collectors;

public class CollectionFeuillesSalaire {

	private ArrayList<FeuilleSalaire> listeFeuilleSalaire;
	
	public CollectionFeuillesSalaire() {
		this.listeFeuilleSalaire = new ArrayList<FeuilleSalaire>();
	}
	
	public void ajouter(FeuilleSalaire f) {
		this.listeFeuilleSalaire.add(f);
	}
	
	public void print() {
		listeFeuilleSalaire.stream().forEach(System.out::println);
//		for (FeuilleSalaire fs : listeFeuilleSalaire) {
//			System.out.println(fs);
//		}
//		listeFeuilleSalaire.stream().forEach(fs -> System.out.println(fs));
	}
	
	public void tri1() {
		for (int i = listeFeuilleSalaire.size()-1; i >= 1; i--) {
			for (int j = 0; j <= i-1; j++) {
				if (listeFeuilleSalaire.get(j+1).getNbHeure() < listeFeuilleSalaire.get(j).getNbHeure()) {
					FeuilleSalaire f = listeFeuilleSalaire.get(j);
					listeFeuilleSalaire.set(j, listeFeuilleSalaire.get(j+1));
					listeFeuilleSalaire.set(j+1, f);
				}
			}
		}
	}
	
	public void tri2() {}
	public void tri3() {}
	
	public ArrayList<FeuilleSalaire> getFeuilleSalaire(String entreprise){
		ArrayList<FeuilleSalaire> fs =
			(ArrayList<FeuilleSalaire>) listeFeuilleSalaire
			.stream()
			.filter(f -> f.getEmployer().equalsIgnoreCase(entreprise))
			.collect(Collectors.toList());
		
		return fs;
	}
	
	public ArrayList<String> getEntrepriseContaining(String str){
		ArrayList<String> ent =
				(ArrayList<String>) listeFeuilleSalaire
				.stream()
				.filter(f -> f.getEmployer().toLowerCase().contains(str.toLowerCase()))
				.map(f -> f.getEmployer())
				.collect(Collectors.toList());
		return ent;
	}
}

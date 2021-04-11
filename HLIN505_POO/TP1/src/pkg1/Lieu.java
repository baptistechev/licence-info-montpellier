package pkg1;

import java.util.ArrayList;

public enum Lieu {
	stadeDeFoot("Stade de foot"),
	gymnase("Gymnase"),
	terrainDeTennis("Terrain de Tennis");
	
	private String nom;
	private ArrayList<Creneau> creneauDispo;
	
	private Lieu(String nom) {
		this.nom=nom;
		this.creneauDispo = new ArrayList<Creneau>();
	}
	
	public void ajoutCreneau(Creneau c) {
		creneauDispo.add(c);
	}
	
	@Override
	public String toString() {
		String str = this.nom + "[";
		for (Creneau c : creneauDispo) {
			str += c + " ";
		}
		return str + "]";
	}
}

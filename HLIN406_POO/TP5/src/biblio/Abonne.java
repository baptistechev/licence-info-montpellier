package biblio;

import java.util.ArrayList;

public class Abonne {
	private int numAbo;
	private boolean mineur;
	private ArrayList<Exemplaire> livres = new ArrayList<Exemplaire>();
	private int nbLivre = 0;
	
	public Abonne(int numAbo, boolean mineur) {
		this.numAbo = numAbo;
		this.mineur = mineur;
	}

	public void emprunter(Notice n) {
		if(nbLivre <= 5) {
			if(n.estDispo()) {
					if(!mineur || n.getCible()!=Public.ADULTE ) {
						int i = 0;
						Exemplaire e = n.getExemplaires().get(i);
						while(!e.isDispo()) {
							i++;
							e = n.getExemplaires().get(i);
						}
						e.setDispo(false);
						livres.add(e);
						nbLivre++;
					}else {
						System.out.println("Le livre contient un contenue interdit aux mineurs !");
					}
				}else {
					System.out.println("Le livre \"" + n.getTitre() + "\" n'est plus disponible !");
				}
		}else {
			System.out.println("Nombre max de livre atteint !");
		}
	}
	
	public void rendre(Exemplaire e) {
		e.setDispo(true);
		for(int i =0;i<nbLivre;i++) {
			if(livres.get(i)==e) {
				livres.remove(i);
			}
		}
		nbLivre--;
	}
	
	@Override
	public String toString() {
		return "Abonne [numAbo=" + numAbo + ", mineur=" + mineur + "]";
	}
	
	public void affiche() {
		System.out.println(toString());
		for (Exemplaire exemplaire : livres) {
			System.out.println(exemplaire);
		}
	}
	
	
	
	
}

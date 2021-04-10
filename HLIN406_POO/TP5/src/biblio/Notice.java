package biblio;

import java.util.ArrayList;

public class Notice {
	private String ISBN;
	private String titre;
	private String sousTitre;
	private Public cible;
	private ArrayList<Contribution> contributions;
	private ArrayList<Exemplaire> exemplaires;
	
	public String getISBN() {
		return ISBN;
	}

	public String getTitre() {
		return titre;
	}

	public String getSousTitre() {
		return sousTitre;
	}

	public Public getCible() {
		return cible;
	}
	
	public ArrayList<Contribution> getContributions() {
		return contributions;
	}
	
	public ArrayList<Exemplaire> getExemplaires(){
		return exemplaires;
	}

	public Notice(String iSBN, String titre, Public cible) {
		ISBN = iSBN;
		this.titre = titre;
		this.cible = cible;
		contributions = new ArrayList<Contribution>();
		exemplaires = new ArrayList<Exemplaire>();
	}
	
	public Notice(String iSBN, String titre, String sousTitre, Public cible) {
		ISBN = iSBN;
		this.titre = titre;
		this.sousTitre = sousTitre;
		this.cible = cible;
		contributions = new ArrayList<Contribution>();
		exemplaires = new ArrayList<Exemplaire>();
	}
	
	public ArrayList<Contributeur> getContributeurs() {
		ArrayList<Contributeur> contributeurs = new ArrayList<Contributeur>();
		for (Contribution c : contributions) {
			contributeurs.add(c.getContributeur());
		}
		
		return contributeurs;
	}
	
	public void addContributeur(Contributeur c, NatureCtr n) {
		Contribution con = new Contribution(n, this, c);
		contributions.add(con);
		c.getContributions().add(con);
	}
	
	public void addExemplaire(Exemplaire e) {
		exemplaires.add(e);
	}
	
	public boolean estDispo(){
		boolean dispo = false;
		for (Exemplaire exemplaire : exemplaires) {
			if(exemplaire.isDispo()) {
				dispo = true;
			}
		}
		return dispo;
	}

	@Override
	public String toString() {
		return "Notice [ISBN=" + ISBN + ", titre=" + titre + ", sousTitre=" + sousTitre + ", cible=" + cible +"]";
	}
	
	public void affiche(){
		System.out.println(toString());
		for (Exemplaire exemplaire : exemplaires) {
			System.out.println(exemplaire);
		}
	}
	
	
	
}

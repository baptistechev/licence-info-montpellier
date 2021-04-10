package biblio;

import java.util.ArrayList;

public class Contributeur {

	private String nom;
	private String prenom;
	private ArrayList<Contribution> contributions;
	
	public Contributeur(String nom, String prenom) {
		this.nom = nom;
		this.prenom = prenom;
		contributions = new ArrayList<Contribution>();
	}
	
	public ArrayList<Notice> getNotices() {
		ArrayList<Notice> notices = new ArrayList<Notice>();
		for (Contribution c : contributions) {
			notices.add(c.getNotice());
		}
		return notices;
		
	}

	public ArrayList<Contribution> getContributions() {
		return contributions;
	}

	@Override
	public String toString() {
		return "Contributeur [nom=" + nom + ", prenom=" + prenom + "]";
	}
	
	
}

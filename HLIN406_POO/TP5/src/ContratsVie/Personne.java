package ContratsVie;

import java.util.ArrayList;

public class Personne {
	private String nom;
	private String prenom;
	private Sexe sexe;
	private ContratVieCommune ctrActuel;
	private ArrayList<ContratVieCommune> anciensCtr;
	
	public Personne(String nom, String prenom, ContratsVie.Sexe sexe) {
		super();
		this.nom = nom;
		this.prenom = prenom;
		this.sexe = sexe;
		anciensCtr = new ArrayList<ContratVieCommune>();
	}
	
	public void setCtrActuel(ContratVieCommune ctr) {
		this.ctrActuel = ctr;
	}
	
	public void seMarie(Personne p, int date, Organisme mairie, String celebrateur, TCtr typeDeContrat) {
		if(ctrActuel == null && p.ctrActuel==null) {
			Mariage m = new Mariage(date, mairie, celebrateur, typeDeContrat);	
			ctrActuel = m;
			p.setCtrActuel(m);
			ctrActuel.setCouple(this, p);
		}
	}
	
	public void sePacse(Personne p, int date, Organisme tribunal) {
		if(ctrActuel == null && p.ctrActuel==null) {
			PACS pacs = new PACS(date, tribunal);	
			ctrActuel = pacs;
			p.setCtrActuel(pacs);
			ctrActuel.setCouple(this, p);
		}
	}
	
	public Personne getPartenaire() {
		return ctrActuel.getPartenaire(this);
	}
	
	public void ajouterAncienCtr(ContratVieCommune ctr) {
		anciensCtr.add(ctr);
	}
	
	public void resilierCtr(int date) {
		if(ctrActuel != null) {
			ctrActuel.setDateF(date);
			getPartenaire().ajouterAncienCtr(ctrActuel);
			getPartenaire().setCtrActuel(null);
			anciensCtr.add(ctrActuel);
			ctrActuel = null;
		}
	}

	@Override
	public String toString() {
		return "Personne [nom=" + nom + ", prenom=" + prenom + ", sexe=" + sexe +"]";
	}
	
	public void afficheContrats() {
		System.out.println(ctrActuel);
	}
	
	public void afficheAncienContrats() {
		for (ContratVieCommune ctr : anciensCtr) {
			System.out.println(ctr);
		}
	}
	
	
}

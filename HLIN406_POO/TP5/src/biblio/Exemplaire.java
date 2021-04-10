package biblio;

public class Exemplaire{
	
	private boolean dispo;
	private Etat etat;
	private Notice livre;
	
	public Exemplaire(Notice n, boolean dispo, Etat etat) {
		livre = n;
		this.dispo = dispo;
		this.etat = etat;
	}
	
	public void reparation() {
		dispo = !(dispo);
	}

	public boolean isDispo() {
		return dispo;
	}

	public void setDispo(boolean dispo) {
		this.dispo = dispo;
	}

	public Etat getEtat() {
		return etat;
	}
	
	public Notice getLivre() {
		return livre;
	}

	public void setEtat(Etat etat) {
		this.etat = etat;
	}

	@Override
	public String toString() {
		return "Exemplaire [livre = "+ livre + ", dispo=" + dispo + ", etat=" + etat + "]";
	}

	
	
	
	
	
}

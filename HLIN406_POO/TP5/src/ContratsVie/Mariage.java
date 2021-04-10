package ContratsVie;

public class Mariage extends ContratVieCommune{

	private Organisme mairie;
	private String celebrateur;
	private TCtr typeDeContrat;
	
	public Mariage(int dateD, Organisme mairie, String celebrateur, TCtr typeDeContrat) {
		super(dateD);
		this.mairie = mairie;
		this.celebrateur = celebrateur;
		this.typeDeContrat = typeDeContrat;
	}

	@Override
	public String toString() {
		return "Mariage [ "+super.toString()+" mairie=" + mairie + ", celebrateur=" + celebrateur + ", typeDeContrat=" + typeDeContrat + "]";
	}
	
	
	
}

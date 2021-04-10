package FA;

public class Personne {
	private String nom;
	private String prenom;
	
	public Personne(String nom, String prenom) {
		super();
		this.nom = nom;
		this.prenom = prenom;
	}


	@Override
	public String toString() {
		return "[ "+this.nom +" " + this.prenom + " ]";
	}
}

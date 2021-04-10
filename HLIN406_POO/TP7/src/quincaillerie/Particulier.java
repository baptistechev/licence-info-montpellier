package quincaillerie;

public class Particulier extends Client{
	private String prenom;
	private Civilite civilite;
	private Sexe sexe;
	
	public Particulier(String nom, String adressePost, String mail, String prenom, Civilite civilite, Sexe sexe) {
		super(nom, adressePost, mail);
		this.prenom = prenom;
		this.civilite = civilite;
		this.sexe = sexe;
	}

	@Override
	public String toString() {
		return super.toString()+"\nprenom : "+prenom+"\nCivilité : "+civilite+"\nSexe : "+sexe;
	}
	
	
	
}

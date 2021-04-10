package quincaillerie;

public class Entreprise extends Client{
	private String SIRET;

	public Entreprise(String nom, String adressePost, String mail, String sIRET) {
		super(nom, adressePost, mail);
		SIRET = sIRET;
	}
	
	@Override
	public String toString() {
		return super.toString()+"\nSIRET : "+SIRET;
	}
}

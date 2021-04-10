package quincaillerie;

import java.util.HashMap;

public class GestionClients {
	private HashMap<String,Client> listeClients;
	
	
	public GestionClients() {
		listeClients = new HashMap<String, Client>();
	}
	
	public void nouvelEntreprise(String nom, String adressePost, String mail, String sIRET) {
		listeClients.put(mail, new Entreprise(nom, adressePost, mail, sIRET));
	}
	
	public void nouveauParticulier(String nom, String adressePost, String mail,String prenom, Civilite civilite, Sexe sexe) {
		listeClients.put(mail, new Particulier(nom, adressePost, mail, prenom, civilite, sexe));
	}
	
	public Client getClient(String mail) {
		return (listeClients.containsKey(mail)) ? listeClients.get(mail) : null;
	}
	
	public void afficherListeClient() {
		for (Client c : listeClients.values()) {
			System.out.println(c);
		}
	}
	
}

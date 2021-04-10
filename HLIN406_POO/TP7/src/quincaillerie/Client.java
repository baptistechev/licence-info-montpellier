package quincaillerie;

public class Client {
	private String nom;
	private String adressePost;
	private String mail;
	private CarteFidelite carteFidelite;
	
	public Client(String nom, String adressePost, String mail) {
		this.nom = nom;
		this.adressePost = adressePost;
		this.mail = mail;
		this.carteFidelite = new CarteFidelite();
	}
	
	@Override
	public String toString() {
		return "Nom : "+nom+"\nmail : "+mail+"\nadresse postale : "+adressePost;
	}

	public CarteFidelite getCarteFidelite() {
		return carteFidelite;
	}
	
	
}

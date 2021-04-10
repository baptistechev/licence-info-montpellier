package quincaillerie;

public class Vente {

	private boolean paye = false;
	private Client client;
	private Panier panier;
	
	
	
	public Vente(Panier panier) {
		this.panier = panier;
	}



	public String getFacture() {
		return "jsp";
	}



	public void setClient(Client client) {
		this.client = client;
	}



	public Panier getPanier() {
		return panier;
	}
	
	
	
	
}

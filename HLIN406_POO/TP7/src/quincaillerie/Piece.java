package quincaillerie;

public abstract class Piece {
	private String nom;
	private String ref;
	
	public String getNom() {
		return nom;
	}

	public String getRef() {
		return ref;
	}

	public Piece(String nom, String ref) {
		this.nom = nom;
		this.ref = ref;
	}
	
	public abstract float prix();
	public abstract int garantie();
	public abstract int dFabrication();
	
	@Override
	public String toString() {
		return "Nom : "+nom+" \nreference : "+ref+"\nprix : "+prix()+" \ngarantie : "+garantie()+"\ndurée de fabrication : "+dFabrication();

	}
	
	public String toString2() {
		return nom+"-"+ref+"\n" ;
	}
}

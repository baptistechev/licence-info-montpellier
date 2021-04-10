package quincaillerie;

public class ElementPanier {
	private int quantite;
	private Piece piece;
	
	public ElementPanier(int quantite, Piece piece) {
		this.quantite = quantite;
		this.piece = piece;
	}
	
	public void incrQuantite(int x) {
		quantite = getQuantite() + x;
	}
	
	public void decrQuantite(int x) {
		quantite = getQuantite() - x;
	}

	public Piece getPiece() {
		return piece;
	}

	public int getQuantite() {
		return quantite;
	}

	@Override
	public String toString() {
		return quantite+" * "+piece.getNom()+"("+piece.getRef()+") --- "+piece.prix();
	}

	
	
}

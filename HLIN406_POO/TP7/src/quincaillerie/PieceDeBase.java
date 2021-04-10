package quincaillerie;

public class PieceDeBase extends Piece{

	private float prix;
	private int garantie;
	private int dFabrcation;
	
	public PieceDeBase(String nom, String ref, float prix, int garantie, int dFabrcation) {
		super(nom, "00"+ref);
		this.prix = prix;
		this.garantie = garantie;
		this.dFabrcation = dFabrcation;
	}

	@Override
	public float prix() {
		return prix;
	}

	@Override
	public int garantie() {
		return garantie;
	}

	@Override
	public int dFabrication() {
		return dFabrcation;
	}
	
}

package quincaillerie;

import java.util.ArrayList;

public class PieceComposite extends Piece{

	private ArrayList<Piece> listePiece;

	public PieceComposite(String nom, String ref) {
		super(nom, ref);
		this.listePiece = new ArrayList<Piece>();
	}

	@Override
	public float prix() {
		float prix = 0;
		for (Piece p : listePiece) {
			prix += p.prix();
		}
		return prix;
	}

	@Override
	public int garantie() {
		int min = listePiece.get(0).garantie();
		for (Piece p : listePiece) {
			if(p.garantie()<min) {
				min = p.garantie();
			}
		}
		return min;
	}
	
	@Override
	public int dFabrication() {
		int max = listePiece.get(0).dFabrication();
		for (Piece p : listePiece) {
			if(p.dFabrication()>max) {
				max = p.dFabrication();
			}
		}
		return max;
	}
	
	public void ajoute(Piece p) {
		listePiece.add(p);
	}
	
	@Override
	public String toString() {
		return super.toString();
	}

	public ArrayList<Piece> getListePiece() {
		return listePiece;
	}

	
}

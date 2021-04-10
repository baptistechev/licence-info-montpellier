package quincaillerie;

import java.util.ArrayList;

public class Panier {
	private static int nbPaniers = 0;
	private int num;
	private boolean verouille = false;
	private ArrayList<ElementPanier> piecesChoisies;
	
	public Panier() {
		nbPaniers++;
		num = nbPaniers;
		piecesChoisies = new ArrayList<ElementPanier>();
	}

	public int getNum() {
		return num;
	}

	public boolean isVerouille() {
		return verouille;
	}
	
	public void ajouterPanier(Piece p) {
		if(verouille) return;
		piecesChoisies.add(new ElementPanier(1, p));
	}
	
	public void retirerPanier(Piece p) {
		if(verouille) return;
		for (int i = 0; i < piecesChoisies.size(); i++) {
			if(piecesChoisies.get(i).getPiece()==p)
				piecesChoisies.remove(i);
		}
	}
	
	public void decrementerQuantite(Piece p) {
		if(verouille) return;
		for (ElementPanier e : piecesChoisies) {
			if(e.getPiece()==p) {
				e.decrQuantite(1);
				if(e.getQuantite() == 0) {
					this.retirerPanier(p);
					return;
				}
			}
		}
	}
	
	public void incrementerQuantite(Piece p) {
		if(verouille) return;
		for (ElementPanier e : piecesChoisies) {
			if(e.getPiece()==p) {
				e.incrQuantite(1);
				return;
			}
		}
		ajouterPanier(p);
	}
	
	public boolean pieceExistante(Piece p) {
		for (ElementPanier e : piecesChoisies) {
			if(e.getPiece()==p)
				return true;
		}
		return false;
	}
	
	public ElementPanier recherchePiece(String ref) {
		for (ElementPanier e : piecesChoisies) {
			if(e.getPiece().getRef().equalsIgnoreCase(ref))
				return e;
		}
		return null;
	}
	
	public void Valider() {
		verouille = true;
	}

	@Override
	public String toString() {
		String str =  "Panier : \nnum : " + num + "\nêtat : " + ((verouille)?"verouille":"non-verouille") + "\nPieces : \n";
		for (ElementPanier e : piecesChoisies) {
			str += e.toString()+"\n";
		}
		str+="Total : "+getPrix();
		return str;
	}
	
	public float getPrix() {
		float prix = 0;
		for (ElementPanier e : piecesChoisies) {
			prix += e.getQuantite() * e.getPiece().prix();
		}
		return prix;
	}
	
	
}

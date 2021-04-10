package quincaillerie;

public class PieceCompositeMonte extends PieceComposite{

	private float prixMontage;
	private int dureeMontage;
	
	public PieceCompositeMonte(String nom, String ref, float prixMontage, int dureeMontage) {
		super(nom, "02"+ref);
		this.prixMontage = prixMontage;
		this.dureeMontage = dureeMontage;
	}

	@Override
	public int garantie() {
		return super.garantie()+6;
	}

	@Override
	public int dFabrication() {
		return super.dFabrication()+dureeMontage;
	}
	
	@Override
	public float prix() {
		return super.prix()+prixMontage;
	}

	@Override
	public String toString() {
		String str = super.toString()+"\ndurée de montage atelier : "+dureeMontage+"\nprix du montage : "+prixMontage+"\ncomposants : \n";
		for (Piece p: super.getListePiece()) {
			str+="	"+p.toString2();
		}
		return str;
	}
	
	public String toString2() {
		String str=super.getNom()+"-"+super.getRef()+"\n";
		for (Piece p : super.getListePiece()) {
			str+="	"+"	"+p.toString2();
		}
		return str;
	}
	
	public void affiche() {
		System.out.println(toString());
	}

	

	
	
}

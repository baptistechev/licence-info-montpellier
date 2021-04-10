package quincaillerie;

public class PieceCompositeEnKit extends PieceComposite{
	
	private int dureeMontageParticulier;

	public PieceCompositeEnKit(String nom, String ref, int dureeMontageParticulier) {
		super(nom, "01"+ref);
		this.dureeMontageParticulier = dureeMontageParticulier;
	}

	@Override
	public int garantie() {
		return super.garantie()/2;
	}

	@Override
	public String toString() {
		String str = super.toString()+"\ndurée de montage particulier : "+dureeMontageParticulier+"\ncomposants : \n";
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

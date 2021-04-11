package pkg5;

public class CoupleEspece<E extends Espece<E>,A extends Espece<E>,B extends Espece<E>> extends Paire<A, B> {

	public CoupleEspece() {
		// TODO Auto-generated constructor stub
		super();
	}
	
	public CoupleEspece(A f, B s) {
		super(f,s);
	}
}

package pkg5;

public class CoupleFertile<E extends Espece<E>,A extends Espece<E> & Male, B extends Espece<E> & Femelle> extends Paire<A,B>{
	public CoupleFertile() {
		// TODO Auto-generated constructor stub
		super();
	}
	
	public CoupleFertile(A f, B s) {
		super(f,s);
	}
}

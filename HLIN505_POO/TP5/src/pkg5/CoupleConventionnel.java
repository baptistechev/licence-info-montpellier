package pkg5;

public class CoupleConventionnel<A extends Male, B extends Femelle> extends Paire<A,B>{
	
	public CoupleConventionnel() {
		// TODO Auto-generated constructor stub
		super();
	}
	
	public CoupleConventionnel(A f, B s) {
		super(f,s);
	}

}

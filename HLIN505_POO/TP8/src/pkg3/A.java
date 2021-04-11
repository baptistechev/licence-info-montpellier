package pkg3;

public class A {
	
	@InjectMe
	public B b;
	
	public void m() {
		System.out.println("Je suis m dans A");
		b.n();
	}

}

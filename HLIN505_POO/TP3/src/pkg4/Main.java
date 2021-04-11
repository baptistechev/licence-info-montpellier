package pkg4;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Compte c = new Compte(2000, 100);
		System.out.println(c);
		
		c.crediter(-4000);
		
		System.out.println(c);
		
	}

}

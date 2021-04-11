package pkg3;

import com.google.java.contract.Ensures;

public class Main {

	public static void main(String[] args) {
		
		ListeChainee l = new ListeChainee(3);
		l.add(5);
		l.add(6);
		l.addHead(2);
		System.out.println(l);
		System.out.println(l.taille());
		System.out.println(l.renverser());

		
		
	}

}

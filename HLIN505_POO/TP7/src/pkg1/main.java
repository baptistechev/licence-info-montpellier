package pkg1;

import java.awt.Color;

public class main {

	public static void main(String[] args) {
		
		feuTricolore f = new feuTricolore();
		
		for (Color c : f) {
			System.out.println(c);
		}

	}

}

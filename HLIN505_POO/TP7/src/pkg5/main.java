package pkg5;

import java.util.ArrayList;
import java.util.Iterator;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		ArrayList<Double> a = new ArrayList<Double>();
		a.add(3.0); a.add(4.0); a.add(5.0); a.add(6.0); a.add(7.0);
		
		SuiteConstanteRang suite = new SuiteConstanteRang(a,(double) 8);

		Iterator<Double> it = suite.iterator();
		
		for (int i=0; i<14; i++) System.out.println(it.next());
		for (double e : suite) System.out.println(e);
	}

}

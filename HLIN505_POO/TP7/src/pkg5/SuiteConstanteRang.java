package pkg5;

import java.util.ArrayList;
import java.util.Iterator;

public class SuiteConstanteRang implements Iterable<Double>{
	private ArrayList<Double> elem;
	private Double Limit;
	
	public SuiteConstanteRang(ArrayList<Double> elem, Double l) {
		this.elem = elem;
		this.Limit = l;
	}

	@Override
	public Iterator<Double> iterator() {
		return new IterateurSuiteConstanteRang(elem.listIterator(), Limit);
	}
	
}

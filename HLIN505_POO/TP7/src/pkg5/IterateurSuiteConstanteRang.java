package pkg5;

import java.util.Iterator;
import java.util.ListIterator;

public class IterateurSuiteConstanteRang implements Iterator<Double>{

	private ListIterator<Double> iterateur_elements;
	private Double Limit;
	private int nbAff = 0;
	
	public IterateurSuiteConstanteRang(ListIterator<Double> iterateur_elements,Double l) {
		this.iterateur_elements = iterateur_elements;
		this.Limit = l;
	}
	
	@Override
	public boolean hasNext() {
		return nbAff < 5;
	}

	@Override
	public Double next() {
		if(this.iterateur_elements.hasNext())
			return this.iterateur_elements.next();
		else {
			this.nbAff++;
			return this.Limit;
		}
	}
	
	@Override
	public void remove() {
		if(this.iterateur_elements.hasPrevious() && this.iterateur_elements.hasNext())
			this.iterateur_elements.remove();
	}

}

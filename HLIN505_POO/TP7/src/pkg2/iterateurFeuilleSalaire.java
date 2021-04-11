package pkg2;

import java.util.Iterator;

public class iterateurFeuilleSalaire implements Iterator<Object>{

	private FeuilleSalaire fs;
	private int nbAtt = 0;
	
	public iterateurFeuilleSalaire(FeuilleSalaire f) {
		this.fs = f;
	}
	
	
	@Override
	public boolean hasNext() {
		return nbAtt <= 5;
	}

	@Override
	public Object next() {
		nbAtt++;
		switch(nbAtt) {
		case 1: return this.fs.getEmployer();
		case 2: return this.fs.getSalarie();
		case 3: return this.fs.getConvention();
		case 4: return this.fs.getNbHeure();
		case 5: return this.fs.getPrelevement();
		case 6: return this.fs.getPayeNet();
		}
		return null;
	}
	
	@Override
	public void remove() throws UnsupportedOperationException{
		throw new UnsupportedOperationException();
	}

}

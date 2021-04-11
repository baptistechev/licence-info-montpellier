package pkg1;

import java.awt.Color;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.ListIterator;

public class IterateurFeu implements Iterator<Color>{

	private ArrayList<Color> col;
	private ListIterator<Color> iterateur_elements;
	
	public IterateurFeu(ArrayList<Color> colors) {
		this.col = colors;
		this.iterateur_elements = colors.listIterator();
	}
	
	@Override
	public boolean hasNext() {
		return true;
	}

	@Override
	public Color next() {
		if(!this.iterateur_elements.hasNext())
			this.iterateur_elements = this.col.listIterator();
		
		return this.iterateur_elements.next();
	}

}

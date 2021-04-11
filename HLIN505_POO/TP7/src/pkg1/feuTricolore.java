package pkg1;

import java.awt.Color;
import java.util.ArrayList;
import java.util.Iterator;

public class feuTricolore implements Iterable<Color>{

	private ArrayList<Color> colors;
	
	public feuTricolore() {
		this.colors = new ArrayList<>();
		this.colors.add(Color.green);
		this.colors.add(Color.yellow);
		this.colors.add(Color.red);
	}

	@Override
	public Iterator<Color> iterator() {
		return new IterateurFeu(colors);
	}
	
}

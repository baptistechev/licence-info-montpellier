package FA;

import java.util.ArrayList;

public class FileAttenteStat extends FileAttente implements Stat{

	private int nbEntre;
	private int nbSortie;
	
	@Override
	public int nbEntre() {
		return nbEntre;
	}

	@Override
	public int nbSortie() {
		return nbSortie;
	}
	
	public void entre(Personne p) {
		super.entre(p);
		nbEntre++;
	}
	
	public Personne sort() {
		if(!estVide()) {
			nbSortie++;
		}
		return super.sort();
	}
		
}


package pkg3;

import java.util.ArrayList;

public class FileAttente<A> {

	protected ArrayList<A> contenu;
	public FileAttente() {
		// TODO Auto-generated constructor stub
		contenu = new ArrayList<A>();
	}
	public void entre(A a) {
		this.contenu.add(a);
	}
	public A sort() {
		A a = null;
		if(!contenu.isEmpty()) {
			a= contenu.get(0);
			contenu.remove(0);
		}
		return a;
	}
	public boolean estVide() {
		return contenu.isEmpty();
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return ""+contenu;
	}
}

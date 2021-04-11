package pkg4;

import java.util.ArrayList;

public class PochetteDocument<D extends Document> {

	private String theme;
	private ArrayList<D> collection;

	public PochetteDocument(String theme) {
		// TODO Auto-generated constructor stub
		this.theme = theme;
		this.collection = new ArrayList<D>();
	}
	
	public void ajout(D d) throws ajoutDocError {
		collection.add(d);
	}
	
	public int nbDocuments() {
		return this.collection.size();
	}
	
	public void transferDoc(PochetteDocument<? super D> Pd) throws ajoutDocError {
		for (D d : collection) {
			Pd.ajout(d);
		}
		collection = new ArrayList<D>();
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return theme+" ("+nbDocuments()+")";
	}
}

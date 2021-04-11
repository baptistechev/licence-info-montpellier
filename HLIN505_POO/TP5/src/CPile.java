import java.util.LinkedList;

public class CPile<A> implements IPile<A>{

	private LinkedList<A> elements;
	
	public CPile() {
		// TODO Auto-generated constructor stub
		this.elements = new LinkedList<A>();
	}
	
	@Override
	public boolean estVide() {
		// TODO Auto-generated method stub
		return this.elements.isEmpty();
	}

	@Override
	public void empile(A a) {
		// TODO Auto-generated method stub
		this.elements.add(a);
	}

	@Override
	public A depile() {
		// TODO Auto-generated method stub
		return this.elements.removeLast();
	}

	@Override
	public int nbElements() {
		// TODO Auto-generated method stub
		return this.elements.size();
	}

	@Override
	public A sommet() {
		// TODO Auto-generated method stub
		return this.elements.getLast();
	}

	
	
}

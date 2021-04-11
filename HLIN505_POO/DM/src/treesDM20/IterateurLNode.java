package treesDM20;

import java.util.Iterator;
import java.util.Stack;

public class IterateurLNode<T> implements Iterator<LNode<T>>{

	Stack<LNode<T>> pile;
	
	private void remplirPile(LNode<T> n) {
		if(n!=null) {
			
			if(n.getRightNode()!=null)
				remplirPile(n.getRightNode());
			if(n.getLeftNode()!=null)
				remplirPile(n.getLeftNode());
			this.pile.add(n);
			
			
		}
	}
	
	public IterateurLNode(LNode<T> nd) {
		// TODO Auto-generated constructor stub
		this.pile = new Stack<>();
		remplirPile(nd);
	}
	
	@Override
	public boolean hasNext() {
		// TODO Auto-generated method stub
		return !pile.empty();
	}

	@Override
	public LNode<T> next() {
		// TODO Auto-generated method stub
		return pile.pop();
	}

}

package treesDM20;

import java.util.Iterator;

public class LNode<T> extends LabelledElement<T> implements Iterable<LNode<T>>{
	LEdge<?> leftEdge; 
	LEdge<?> rightEdge;
	
	public LNode(T label) {
		super(label);
	} 
	
	public <L> LNode<T> addNewLeftNode(T labeln, L labele) {
		LNode<T> left=new LNode<T>(labeln);
		leftEdge=new LEdge<L>(labele, this, left);
		return left;
	}
	
	public <L> LNode<T> addNewRightNode(T labeln, L labele) {
		LNode<T> right=new LNode<T>(labeln);
		rightEdge=new LEdge<L>(labele, this, right);
		return right;
	}
	
	public String dfsdump() {
		String left=leftEdge!=null?" "+leftEdge.getLabel()+" "+leftEdge.getSon().dfsdump():"";
		String right=rightEdge!=null?" "+rightEdge.getLabel()+" "+rightEdge.getSon().dfsdump():"";
		return label+left+right;
	}
	
	@SuppressWarnings("unchecked")
	public LNode<T> getRightNode(){
		return rightEdge!=null?(LNode<T>)rightEdge.getSon():null;
	}
	
	@SuppressWarnings("unchecked")
	public LNode<T> getLeftNode(){
		return leftEdge!=null?(LNode<T>)leftEdge.getSon():null;
	}

	@Override
	public Iterator<LNode<T>> iterator() {
		return new IterateurLNode<T>(this);
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return  "" +getLabel();
	}
	
}
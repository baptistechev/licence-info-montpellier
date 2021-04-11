package treesDM20;

public class LEdge<T> extends LabelledElement<T>{

	LNode<?> father; 
	LNode<?> son;
	
	public T getLabel() {
		return label;
	}
	
	public <L> LEdge(T label, LNode<L> father,
			LNode<L> son) {
		
		super(label);
		this.father = father;
		this.son = son;
	}

	public LNode<?> getFather() {
		return father;
	}

	public LNode<?> getSon() {
		return son;
	} 
	
	
	
}
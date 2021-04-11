package pkg2;

public class ListeChainee {

	private Node racine;
	
	public ListeChainee(int valeurRacine) {
		this.racine = new Node(valeurRacine, null);
	}
	
	public ListeChainee(Node racine) {
		this.racine = racine;
	}
	
	public void add(int value) {
		Node n = racine;
		while(n.next!=null)
			n = n.next;
		n.next = new Node(value, null);
	}
	
	public void addHead(int value) {
		racine = new Node(value, racine);
	}
	
	public int taille() {
		if(racine==null)
			return 0;
		else
			return 1 + (new ListeChainee(racine.next)).taille();
	}
	
	public ListeChainee renverser() {
		Node n = null;
		Node p = racine;
		Node q;
		while(p.next!=null) {
			q = new Node(p.value, n);
			n = q;
			p = p.next;
		}
		q = new Node(p.value, n);
		return new ListeChainee(q);
		
	}
	
	public String toString() {
		Node n = racine;
		String s = "";
		while(n.next!=null) {
			s += n.value + " -> ";
			n = n.next;
		}
		return s + n.value;
		
	}
	
	private class Node{
	
		private int value;
		private Node next;
		
		private Node(int value, Node next) {
			
			super();
			this.value = value;
			this.next = next;
			
		}	
				
	}
}

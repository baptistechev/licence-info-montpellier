package treesDM20;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		LNode<Integer> pere = new LNode<Integer>(0);
		pere.addNewLeftNode(1, "-g->");
		pere.addNewRightNode(2, "-d->");
		
		pere.getLeftNode().addNewLeftNode(3, "-g->");
		pere.getLeftNode().addNewRightNode(4, "-d->");
		
		pere.getRightNode().addNewLeftNode(5, "-g->");
		pere.getRightNode().addNewRightNode(6, "-d->");
		
		for (LNode<Integer> n : pere) {
			System.out.println(n);
		}
		
		System.out.println(pere.dfsdump());
		
	}

}

package treesDM20;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class TestTrees{

	LNode<String> root=new LNode<String>("root");
	LNode<String> right;
	LNode<String> left;
	
	@BeforeEach
	public void init() {
		left=root.addNewLeftNode("fils1", 1);
		right=root.addNewRightNode("fils2", 2);
	}
	
	@Test
	void testLTrees6nodes() {
		LNode<String> autre=left.addNewLeftNode("fils3", "3");
		autre.addNewLeftNode("fils4", "4");
		autre.addNewRightNode("fils5", "5");
		
		String str = "";
		for (LNode<String> n : this.root) {
			str += n.getLabel() + " ";
		}

		assertEquals("root fils1 fils3 fils4 fils5 fils2 ", str);
	}
	
	@Test
	void testLTreeOverflow() {
		IterateurLNode<String> i = (IterateurLNode<String>) root.iterator();
		while(i.hasNext()) {
			i.next();
		}
		
		assertThrows(Exception.class, () -> i.next());
		
		//--- OU ---
		
		try {
			i.next();
			fail();
		}catch (Exception e){
			assert(true);
		}
	}
	

}

public class Main {

	public static void main(String[] args) {
		
		CPile<Integer> p = new CPile<Integer>();
		p.empile(3);
		p.empile(5);
		System.out.println(p.depile());
		System.out.println(p.nbElements());
		System.out.println(p.estVide());
		
		CPile<String> p2 = new CPile<String>();
		p2.empile("str");
		p2.empile("hello world");
		System.out.println(p2.depile());
	}
}

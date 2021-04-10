package FA;

public class main {

	public static void main(String[] args) {
		
		FileAttenteStat f = new FileAttenteStat();
		Personne p1 = new Personne("Dupont", "Jean");
		Personne p2 = new Personne("Martin", "Michel");
		f.entre(p1);
		f.entre(p2);
		
		System.out.println(f);
		System.out.println(f.nbEntre());
		
		
	}

}

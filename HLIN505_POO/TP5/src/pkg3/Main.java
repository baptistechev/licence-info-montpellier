package pkg3;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		FileAttenteAvecPriorite<Personne> fa = new FileAttenteAvecPriorite<Personne>();
		
		fa.entre(new Personne("Jean", 50));
		fa.entre(new Personne("Boris", 10));
		fa.entre(new Personne("Eude", 89));
		
		System.out.println(fa);
		
		fa.sort();
		System.out.println(fa);
		
		fa.sort();
		System.out.println(fa);
		
		
	}

}

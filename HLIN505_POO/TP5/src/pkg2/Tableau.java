package pkg2;

public class Tableau <A extends Comparable<A>>{

	private A T[];
	
	public Tableau(A T[]) {
		// TODO Auto-generated constructor stub
		this.T = T;
	}
	
	public void TriBulle() {
		int i = T.length -2;
		boolean ech = true;
		while(i>=2 && ech) {
			ech = false;
			for(int j=0;j<=i;j++) {
				if(T[j].compareTo(T[j+1]) > 0){
					A aux = T[j];
					T[j] = T[j+1];
					T[j+1] = aux;
					ech = true;
				}
			}
		}
	}
	
	public void Affiche() {
		for (A a : T) {
			System.out.print(a + " ");
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		Integer T[] = {8, 6, 4, 7, 2, 3, 9, 1, 5};
		Tableau<Integer> obj = new Tableau<Integer>(T);
		obj.TriBulle();
		obj.Affiche();
		
		Double T2[] = {3.157,5.17,1.5698};
		Tableau<Double> obj2 = new Tableau<Double>(T2);
		obj2.TriBulle();
		obj2.Affiche();
	}
}



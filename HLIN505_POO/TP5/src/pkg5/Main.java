package pkg5;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		CoupleConventionnel<Taureau, Vache> c1 = new CoupleConventionnel<>(new Taureau(), new Vache());
		CoupleConventionnel<Taureau, Dauphine> c2 = new CoupleConventionnel<>(new Taureau(), new Dauphine());
		System.out.println(c1);
		System.out.println(c2);
		
		CoupleEspece<ETaureau, Taureau, Vache> ce = new CoupleEspece<>(new Taureau(), new Vache());
		CoupleEspece<EDauphin, Dauphin, Dauphin> ce2 = new CoupleEspece<>(new Dauphin(), new Dauphin());
		System.out.println(ce);
		System.out.println(ce2);
		
		CoupleFertile<ETaureau, Taureau, Vache> cf = new CoupleFertile<>(new Taureau(), new Vache());
		System.out.println(cf);
		
	}

}

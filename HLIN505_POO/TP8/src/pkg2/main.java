package pkg2;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		try {
			
			PersonnageInvisible p = new PersonnageInvisible();
			methodInvoquer mi = new methodInvoquer();
			
			mi.invoque("makeInvisible", p);
			
			
			
			
			
//		genToString ts = new genToString();
//		System.out.println(ts.toString(new PersonnageInvisible(), 0, 2));
		
		
		
		
//		AnnotationManager am = new AnnotationManager();
//		am.listToDo();
//		am.listToDo(TacheType.AMELIORER_COMPLEXITE);
//		System.out.println(am.dureeTotal(1));
		
		
		
		
		
		
//		FabriquePersonnage fabrique = new FabriquePersonnage();

//			Personnage p = fabrique.createPerso("pkg2.PersonnageInvisible");
//			System.out.println(p);
//
//			fabrique.changeAttr(p);
//			System.out.println(p);
//			
//			Personnage p2 = fabrique.convert(p, "pkg2.PersonnageBonus");
//			System.out.println(p2);
//			
//			PersonnageBonus p3 = new PersonnageBonus();
//			Personnage p4 = fabrique.convert(p3, "pkg2.PersonnageInvisible");
//			System.out.println(p4);
//			
//			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}

}

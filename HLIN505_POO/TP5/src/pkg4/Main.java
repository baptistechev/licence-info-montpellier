package pkg4;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		PochetteDocument<GuideVoyage> p1 = new PochetteDocument<GuideVoyage>("Pays chauds");
		PochetteDocument<Document> p2 = new PochetteDocument<Document>("random");
		PochetteDocumentJeunesse<LivreJeunesse> p3 = new PochetteDocumentJeunesse<LivreJeunesse>("les animaux", 13);

//		PochetteDocument<Livre> p4 = new PochetteDocument<LivreJeunesse>("l");
//		PochetteDocument<Livre> p5 = new PochetteDocumentJeunesse<LivreJeunesse>("l", 5);
		
		try {
			p1.ajout(new GuideVoyage());
			p2.ajout(new GuideVoyage());
			p2.ajout(new LivreJeunesse(8));
			
			p3.ajout(new LivreJeunesse(12));
//			p3.ajout(new LivreJeunesse(17));
			
			p1.transferDoc(p2);
			
		} catch (ajoutDocError e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		System.out.println(p1);
		System.out.println(p2);
		System.out.println(p3);
	}

}

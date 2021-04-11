package pkg3;

public class FileAttenteAvecPriorite<A extends ElementAvecPriorite> extends FileAttente<A>{
	
	public FileAttenteAvecPriorite() {
		// TODO Auto-generated constructor stub
		super();
	}
	
	@Override
	public A sort() {
		A a = null;
		if(!contenu.isEmpty()) {
			a= lePlusPrioritaire();
			contenu.remove(a);
		}
		return a;
	}
	
	public A lePlusPrioritaire() {
		A a = null;
		int priorite = Integer.MAX_VALUE;
		for (A e : contenu) {
			if(e.priorite() < priorite) {
				priorite = e.priorite();
				a = e;
			}
		}
		return a;
	}
	
}

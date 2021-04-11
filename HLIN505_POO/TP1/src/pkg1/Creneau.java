package pkg1;

public class Creneau {
	private jourSemaine jour;
	private Heure hDebut;
	private Heure hFin;
	
	
	public Creneau(jourSemaine jour, Heure hDebut, Heure hFin) {
		super();
		this.jour = jour;
		this.hDebut = hDebut;
		this.hFin = (hDebut.compareTo(hFin) >= 0) ? hFin : hDebut;
	}
	
	public jourSemaine getJour() {
		return jour;
	}

	public Heure gethDebut() {
		return hDebut;
	}

	public Heure gethFin() {
		return hFin;
	}


	public boolean inclut(Creneau c) {
		return (jour == c.getJour()) && (hDebut.compareTo(c.gethDebut()) >= 0) && (hFin.compareTo(c.gethFin()) <= 0);
	}
	
	public boolean chevauche(Creneau c) {
		if(inclut(c)) {
			return true;
		}else {
			if(hDebut.compareTo(c.gethDebut()) <= 0) {
				return hDebut.compareTo(c.gethFin()) >= 0;
			}else {
				return hFin.compareTo(c.gethDebut()) <= 0;
			}
		}
	}
	
	@Override
	public String toString() {
		return jour +" "+ hDebut +" -- " + hFin;
	}
	
}

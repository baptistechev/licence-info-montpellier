package pkg1;

public class Creneau2 {
	private jourSemaine jour;
	private Heure2 hDebut;
	private Heure2 hFin;
	
	
	public Creneau2(jourSemaine jour, int h1, int min1, int h2, int min2) {
		super();
		this.jour = jour;
		this.hDebut = new Heure2(h1, min1);
		this.hFin = new Heure2(h2, min2);
		this.hFin = (this.hDebut.compareTo(this.hFin) >= 0) ? this.hFin : this.hDebut;
	}
	
	public jourSemaine getJour() {
		return jour;
	}

	public Heure2 gethDebut() {
		return hDebut;
	}

	public Heure2 gethFin() {
		return hFin;
	}


	public boolean inclut(Creneau2 c) {
		return (jour == c.getJour()) && (hDebut.compareTo(c.gethDebut()) >= 0) && (hFin.compareTo(c.gethFin()) <= 0);
	}
	
	public boolean chevauche(Creneau2 c) {
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
	
	private class Heure2 implements Comparable<Heure2>{
		private int heure;
		private int min;
		
		private Heure2(int heure, int min) {
			this.heure = (heure<=24 && heure >=0) ? heure : 0;
			this.min = (min<=60 && heure >=0) ? min-min%5 : 0;
		}
		
		@Override
		public int compareTo(Heure2 anotherHeure) {
			if(this.heure == anotherHeure.heure) {
				if(this.min == anotherHeure.min) {
					return 0;
				}else
					return (this.min > anotherHeure.min) ? -1 : 1;
			}else 
				return (this.heure > anotherHeure.heure)? -1 : 1;
		}
		
		@Override
		public String toString() {
			return heure + "h" + min;
		}
		
		
	}
}

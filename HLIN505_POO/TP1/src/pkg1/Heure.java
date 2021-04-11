package pkg1;

import java.util.Comparator;

public class Heure implements Comparable<Heure>{
	private int heure;
	private int min;
	
	public Heure(int heure, int min) {
		this.heure = (heure<=24 && heure >=0) ? heure : 0;
		this.min = (min<=60 && heure >=0) ? min-min%5 : 0;
	}
	
	@Override
	public int compareTo(Heure anotherHeure) {
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

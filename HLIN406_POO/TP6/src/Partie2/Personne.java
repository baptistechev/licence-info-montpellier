package Partie2;

public class Personne implements Comparable<Personne>{
	private String nom;
	private String prenom;
	
	public Personne(String nom, String prenom) {
		this.nom = nom;
		this.prenom = prenom;
	}


	@Override
	public String toString() {
		return "[ "+this.nom +" " + this.prenom + " ]";
	}


	@Override
	public int compareTo(Personne anotherPerson) {
		if(this.nom.compareTo(anotherPerson.nom) > 0) {
			return 1;
		}else if(this.nom.compareTo(anotherPerson.nom) == 0) {
			return this.prenom.compareTo(anotherPerson.prenom);
		}else {
			return -1;
		}
		
	}
}

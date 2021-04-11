package pkg2;

import java.util.Scanner;

public abstract class Personnage {

	private String nom;
	private int nbPoints;
	private int nbVies;
	
	public Personnage() {
		this.nom="Perso";
		this.nbPoints=0;
		this.nbVies=1;
	}

	public Personnage(String nom, int nbPoints, int nbVies) {
		this.nom = nom;
		this.nbPoints = nbPoints;
		this.nbVies = nbVies;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public int getNbPoints() {
		return nbPoints;
	}

	@Todo(type = TacheType.AMELIORER_COMPLEXITE, duree = 53)
	public void setNbPoints(int nbPoints) {
		this.nbPoints = nbPoints;
	}

	public int getNbVies() {
		return nbVies;
	}

	public void setNbVies(int nbVies) {
		this.nbVies = nbVies;
	}

	@Override
	public String toString() {
		return "Personnage [nom=" + nom + ", nbPoints=" + nbPoints + ", nbVies=" + nbVies + "]";
	}

	@Todo(type = TacheType.AMELIORER_COMPLEXITE, duree = 20, numVersion = 2)
	public void changeAttr() {
		Scanner sc = new Scanner(System.in);
		
		String str = sc.nextLine();
		setNom(str);
		int i = sc.nextInt();
		setNbPoints(i);
		i = sc.nextInt();
		setNbVies(i);
	}

}

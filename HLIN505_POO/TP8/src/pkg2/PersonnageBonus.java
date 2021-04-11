package pkg2;

public class PersonnageBonus extends Personnage{
	private int seuil=10;
	public void setNbPoints(int nbPoints) {
		super.setNbPoints(nbPoints);
		if (getNbPoints()>seuil) {
			setNbVies(getNbVies()+1);
			seuil+=10;// nouveau seuil, un seuil ne donne qu'une fois droit à une vie supplémentaire
		}
	}
	
	@Todo(type = TacheType.ECRIRE, duree = 10, numVersion = 1)
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return super.toString() + "Bonus";
	}
	
}

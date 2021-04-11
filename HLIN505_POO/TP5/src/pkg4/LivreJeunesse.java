package pkg4;

public class LivreJeunesse extends Livre implements DocumentJeunesse{

	private int ageMin;
	
	public LivreJeunesse(int ageMin) {
		// TODO Auto-generated constructor stub
		this.ageMin = ageMin;
	}
	
	@Override
	public int getAgeMin() {
		// TODO Auto-generated method stub
		return ageMin;
	}
	
}

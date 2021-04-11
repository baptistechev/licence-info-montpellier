package pkg4;

public class PochetteDocumentJeunesse<D extends DocumentJeunesse> extends PochetteDocument<D> implements DocumentJeunesse{

	private int ageMin;
	
	public PochetteDocumentJeunesse(String theme, int ageMin) {
		super(theme);
		this.ageMin = ageMin;
		// TODO Auto-generated constructor stub
	}

	@Override
	public void ajout(D d) throws ajoutDocError{
		// TODO Auto-generated method stub
		if(d.getAgeMin() <= this.getAgeMin())
			super.ajout(d);
		else
			throw new ajoutDocError();
	}
	
	@Override
	public int getAgeMin() {
		// TODO Auto-generated method stub
		return this.ageMin;
	}

}

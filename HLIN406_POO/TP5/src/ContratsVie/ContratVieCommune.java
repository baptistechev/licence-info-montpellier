package ContratsVie;

import java.util.ArrayList;

public class ContratVieCommune {
	private int dateD;
	private int dateF = -1;
	private Personne[] couple = new Personne[2];
	
	public ContratVieCommune(int dateD) {
		super();
		this.dateD = dateD;
	}

	public void setDateF(int dateF) {
		this.dateF = dateF;
	}

	@Override
	public String toString() {
		return "ContratVieCommune [dateD=" + dateD + ", dateF=" + dateF + ", couple=" + couple[0] + ":" + couple[1] +"]";
	}
	
	public Personne getPartenaire(Personne p) {
		if(couple[0] == p)
			return couple[1];
		else
			return couple[0];
	}

	public void setCouple(Personne p1,Personne p2) {
		couple[0] = p1;
		couple[1] = p2;
	}
	
	
	
}

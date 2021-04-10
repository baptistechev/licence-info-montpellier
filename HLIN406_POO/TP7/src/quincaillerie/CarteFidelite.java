package quincaillerie;

public class CarteFidelite {
	private int points;
	private static int seuil = 30;
	
	public CarteFidelite() {
		// TODO Auto-generated constructor stub
		this.points = 0;
	}

	public static int getSeuil() {
		return seuil;
	}

	public int getPoints() {
		return points;
	}
	
	public void nouvelAchat(float prix) {
		float p = prix;	
		while (p>5) {
			if(this.points<this.seuil)
				this.points++;
			p-=5;
		}
	}
	
	public float calculReductionPossible() {
		if(this.points==30) 
			return 0.15f;
		else if(this.points>=20)
			return 0.09f;
		else if(this.points>=10)
			return 0.04f;
		else
			return 0;
	}
	
	public void applicationReduction() {
		this.points -= (this.points/10)*10;
	}

	@Override
	public String toString() {
		return "CarteFidelite [points=" + points + "]";
	}
	
	
}

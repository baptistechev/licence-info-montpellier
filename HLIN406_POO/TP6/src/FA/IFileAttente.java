package FA;

public interface IFileAttente{

	void entre(Personne p);
	Personne sort();
	boolean estVide();
	int taille();
	
	default void vider(){
		int taille = taille();
		for (int i=0; i<taille; i++)
			this.sort();
	}
	
}

package pkg1;

public class Song extends AbstractAudioElement{

	private String chanteur;
	private int duree;
	private int taille;
	
	
	public Song(int duree, String titre, String fichier, String chanteur) throws IncorrectFileNameException{
		super(titre, fichier);
		this.duree = duree;
		this.chanteur = chanteur;
				
		if(!this.getFile().exists())
			throw new IncorrectFileNameException(fichier);
		
		this.taille = (int) this.getFile().length();
	}

	public String getFichier(boolean includeExtension) {
		return (includeExtension) ? super.getFichier() : super.getFichier().split("\\.")[0];
	}
	
	public String getChanteur() {
		return chanteur;
	}

	@Override
	public int getDuree() {
		// TODO Auto-generated method stub
		return duree;
	}

	@Override
	public int getTaille() {
		// TODO Auto-generated method stub
		return taille;
	}
	
	@Override
	public String toString() {
		return this.getTitre()+" ["+chanteur+"] ("+duree+") : "+this.getFichier();
	}

}

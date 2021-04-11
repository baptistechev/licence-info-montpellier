package pkg1;

import java.io.File;

public abstract class AbstractAudioElement implements IelementAudio{

	private File file;
	private String titre;
	private String fichier;
	

	public AbstractAudioElement(String titre, String fichier) {
		super();
		this.file = new File(fichier);
		this.titre = titre;
		this.fichier = fichier;
	}

	@Override
	public String getTitre() {
		// TODO Auto-generated method stub
		return titre;
	}

	@Override
	public void setTitre(String titre) {
		// TODO Auto-generated method stub
		this.titre = titre;
	}

	@Override
	public String getFichier() {
		// TODO Auto-generated method stub
		return fichier;
	}
	
	public File getFile() {
		return file;
	}
	

	@Override
	public String toString() {
		return "AbstractAudioElement [file=" + file + ", titre=" + titre + ", fichier=" + fichier + "]";
	}
	
	
	
	
}

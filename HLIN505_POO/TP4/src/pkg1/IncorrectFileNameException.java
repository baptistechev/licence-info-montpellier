package pkg1;

public class IncorrectFileNameException extends Exception{

	String fichier;
	
	public IncorrectFileNameException(String fichier) {
		// TODO Auto-generated constructor stub
		super();
		this.fichier = fichier;
	}
	
	public IncorrectFileNameException(String msg, String fichier) {
		// TODO Auto-generated constructor stub
		super(msg);
		this.fichier = fichier;
	}
	
}

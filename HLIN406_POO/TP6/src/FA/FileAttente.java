package FA;

import java.util.ArrayList;

public class FileAttente implements IFileAttente{
	private String nomFile = "File";
	private static String reglementationFile = "sans priorite";
	private ArrayList<Personne> contenu;
	
	public FileAttente(){
		contenu = new ArrayList<Personne>();
	}

	@Override
	public void entre(Personne p) {
		// TODO Auto-generated method stub
		contenu.add(p);
	}

	@Override
	public Personne sort() {
		// TODO Auto-generated method stub
		Personne p=null;
		if (!contenu.isEmpty()){
			p=contenu.get(0);
			contenu.remove(0);
		}
		return p;
	}

	@Override
	public boolean estVide() {
		// TODO Auto-generated method stub
		return contenu.isEmpty();
	}

	@Override
	public int taille() {
		// TODO Auto-generated method stub
		return contenu.size();
	}
	
	public String toString(){return ""+nomFile+" "+reglementationFile+" : "+descriptionContenu();}
	private String descriptionContenu()
	{
		String resultat = "";
		for (Personne p:this.contenu)
			resultat += p + " ";
		return resultat;
	}
}

package pkg1;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class SimplePlaylist extends AbstractAudioElement implements Iplaylist{

	private ArrayList<Song> liste;
	
	/**
	 * Creer une playlist basé sur la classe {@link pkg1.AbstractAudioElement#AbstractAudioElement(String, String)} 
	 */
	public SimplePlaylist(String titre, String fichier){
		super(titre, fichier);
		this.liste = new ArrayList<Song>();
		try {
			fichierExist();
			lectureFichier();
		} catch (IncorrectFileNameException e) {
			creerFichier();
		}
	}

	public void fichierExist() throws IncorrectFileNameException{
		if(!this.getFile().exists())
			throw new IncorrectFileNameException(this.getFichier());
	}
	
	private void lectureFichier() {
		try {
			Scanner myScanner = new Scanner(this.getFile());
			this.setTitre(myScanner.nextLine()); 
			while(myScanner.hasNextLine()) {
				String[] data = myScanner.nextLine().split(":");
				if(data.length == 4) {
					try {
						this.liste.add(new Song(Integer.parseInt(data[2]), data[0], data[3], data[1]));
					} catch (NumberFormatException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					} catch (IncorrectFileNameException e) {
						// TODO Auto-generated catch block
						System.out.println(" !!! Probleme avec le fichier : "+ e.fichier);
					}
				}
					
			}
			myScanner.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public void creerFichier() {
		System.out.println("creation du fichier");
		try {
			this.getFile().createNewFile();
			FileWriter myWriter = new FileWriter(this.getFile());
			myWriter.write(this.getTitre());
			myWriter.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public void reecrire() {
		FileWriter myWriter;
		try {
			myWriter = new FileWriter(this.getFile());
			myWriter.write(this.getTitre());
			for (Song song : liste) {
				myWriter.write("\n"+song.getTitre()+":"+song.getChanteur()+":"+song.getDuree()+":"+song.getFichier());
			}
			myWriter.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Todo(type = TacheType.AMELIORER_COMPLEXITE, duree = 30)
	public void addSong(int duree, String titre, String fichier, String chanteur) {
		try {
			this.liste.add(new Song(duree, titre, fichier, chanteur));
		} catch (IncorrectFileNameException e) {
			// TODO Auto-generated catch block
			System.out.println(" !!! Probleme avec le fichier : "+ e.fichier);
		}	
		reecrire();
	}
	
	@Override
	public int getDuree() {
		int duree = 0;
		for (Song song : liste) {
			duree+= song.getDuree();
		}
		return duree;
	}

	@Override
	public int getTaille() {
		int taille = (int) this.getFile().length();
		for (Song song : liste) {
			taille += song.getTaille();
		}
		return taille;
	}

	@Override
	public int getNombreElements() {
		// TODO Auto-generated method stub
		return liste.size();
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		String str = this.getTitre() + " (" + getDuree() + ") : \n";
		for (Song song : liste) {
			str+= song.toString() + "\n";
		}
		return str;
	}
	
	public Song getSong(int i) {
		return liste.get(i);
	}
	
	public ArrayList<Song> getListeOfSong(){
		return this.liste;
	}
}

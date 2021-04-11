package pkg1;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class PlaylistComposite extends SimplePlaylist{

	private ArrayList<SimplePlaylist> liste;
	
	public PlaylistComposite(String titre, String fichier) {
		super(titre, fichier);
		this.liste = new ArrayList<SimplePlaylist>();
		lectureFichier();
	}
	
	private void lectureFichier() {
		try {
			Scanner myScanner = new Scanner(this.getFile());
			this.setTitre(myScanner.nextLine()); 
			while(myScanner.hasNextLine()) {
				String[] data = myScanner.nextLine().split(":");
				if(data.length == 2) {
					this.liste.add(new SimplePlaylist(data[0], data[1]));
				}									
			}
			myScanner.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void addPlaylist(String titre, String lien) {
		this.liste.add(new SimplePlaylist(titre, lien));
		reecrire();
	}
	
	@Override
	public void reecrire() {
		FileWriter myWriter;
		try {
			myWriter = new FileWriter(this.getFile());
			myWriter.write(this.getTitre());
			for (SimplePlaylist sp : liste) {
				myWriter.write("\n"+sp.getTitre()+":"+sp.getFichier());
			}
			for (Song song : this.getListeOfSong()) {
				myWriter.write("\n"+song.getTitre()+":"+song.getChanteur()+":"+song.getDuree()+":"+song.getFichier());
			}
			myWriter.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	@Override
	public int getDuree() {
		int sum = 0;
		for (SimplePlaylist sp : liste) {
			sum += sp.getDuree();
		}
		sum += super.getDuree();
		return sum;
	}

	@Override
	public int getTaille() {
		int taille = (int) this.getFile().length();
		for (SimplePlaylist sp : liste) {
			taille += sp.getTaille();
		}
		taille += super.getTaille();
		return taille;
	}
	
	@Override
	public int getNombreElements() {
		// TODO Auto-generated method stub
		return liste.size()+super.getNombreElements();
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		String s = this.getTitre() +"[ "+getDuree()+" ]"+ " :\n";
		for (SimplePlaylist sp : liste) {
			s += sp.toString()+"\n";
		}
		s += "\nSong : \n";
		for (Song sg : getListeOfSong()) {
			s += sg.toString()+"\n";
		}
		return s;
	}

}

package pkg1;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		BufferedReader LClavier = new BufferedReader(new InputStreamReader(System.in));
		boolean success = false;
		while(!success) {
			try {
				String fileName = LClavier.readLine();
				BufferedReader LFichier = new BufferedReader(new FileReader(fileName));
				
				success = true;
				String s = LFichier.readLine();
				while(s!=null) {
					System.out.println(s);
					s = LFichier.readLine();
				}
				LFichier.close();
			}
			catch(FileNotFoundException e) {
				System.out.println("Fichier non trouvé !!");
			}
			catch(IOException ioe) {
				System.out.println("Mauvais nom !");
			}	
		}
		System.out.println("Fin du main");
	}

}

package TD2;

import java.time.LocalDate;

public class test{
    public static void main(String[] args){
	
    LocalDate date = LocalDate.of(2003, 05, 06);
	float notes[] = {10,9.3f,13.7f};
		
	Etudiant e = new Etudiant("Michel", date, 0034, 1, notes);
	System.out.println(e.ligneResultat());
	System.out.println(e.toString());
    }
}

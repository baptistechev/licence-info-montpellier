package TD2;

import java.time.LocalDate;
import java.time.Period;

public class Etudiant{

    private String nom;
    private int age;
    private LocalDate dNais;
    private int codeIns;
    private int codePays;
    private float[] notes;

    public Etudiant(String no,LocalDate d,int c,int cp,float[] n){
	nom=no;
	Period t = d.until(LocalDate.now());
	age = t.getYears();
	dNais=d;
	codeIns=c;
	codePays=cp;
	notes=n;
    }

    public void setNom(String n){
	nom=n;
    }
    public void setDNais(LocalDate d){
	dNais=d;
    }
    public void setCodeIns(int c){
	codeIns=c;
    }
    public void setCodePays(int c){
	codePays=c;
    }
    public void setNotes(float[] n){
	notes=n;
    }

    public String getNom(){return nom;}
    public int getAge(){return age;}
    public LocalDate getDNais(){return dNais;}
    public int getCodeIns(){return codeIns;}
    public int getCodePays(){return codePays;}
    public float[] getNotes(){return notes;}

    public float moyenne(){
    	float moyenne = 0;
    	for(int i=0;i<notes.length;i++){
    		moyenne += notes[i];
		}
    	moyenne /= notes.length;
    	return moyenne;
    }
    public String mention(){
    	float moy = moyenne();
    	if(moy>=16){
    		return "TB";
    	}else if(moy>=14){
    		return "Bien";
    	}else if(moy>=12){
    		return "AB";
    	}else{
    		return "Sans Mention";
    	}
    }
    public String ligneResultat(){
    	return nom+" "+String.valueOf(moyenne())+" "+mention();
    }	
    public String toString() {
    	String str = "\nPackage : TD2\nClass : Etudiant\nNom : "+nom+"\nAge : " + age + "\nDate de naissance : " + dNais+"\nCode Inscription : " + codeIns+"\nCode Pays : "+codePays+"\nNotes : ";
    	for (int i = 0; i < notes.length; i++) {
			str += notes[i] + " ";
		}
    	return str;
    }
}

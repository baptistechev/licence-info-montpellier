package poste;

import java.time.LocalDate;

public class ColisExpress extends Colis{

    private LocalDate date;
    private static int nbColisExp;
    private int numSuivi;
    private boolean emballagePoste;

    public ColisExpress(String origine,String destination,int codePostal,int poids,float volume,int txRecommandation,String declContenu, int valeurDeclare,LocalDate date,boolean emballagePoste){
	super(origine,destination,codePostal,poids,volume,txRecommandation,declContenu,valeurDeclare);
	this.date = date;
	this.nbColisExp++;
	this.numSuivi = nbColisExp;
	this.emballagePoste = emballagePoste;
	if(poids>30000){
	    System.out.println("Votre colis ne possedent pas les caracteristique requisent pour l'express !");
	}
    }

    public float tarifAff(){
	int t = 30;
	if(emballagePoste){
	    return t+3;
	}
	return t;
    } 
    public String toString(){
	return "Express " + super.toString()+"/"+super.getPoids()+"/"+numSuivi;
    }    
}

package TP3;

public class Colis extends ObjetPostal{

    private String declContenu;
    private int valeurDeclare;
    private final float tarifBase = 2f;

    public Colis(String origine,String destination,int codePostal,int poids,float volume,int txRecommandation,String declContenu, int valeurDeclare){
	super(origine,destination,codePostal,poids,volume,txRecommandation);
	this.declContenu = declContenu;
	this.valeurDeclare = valeurDeclare;
    }

    public float tarifAff(){
	float t = super.tarifAff();
	if(super.getVolume() > 0.125f){
	    return t+3f;
	}else{
	    return t;
	}
    } 
    public float tarifRemb(){
	if(super.getTxRecommandation() == 1){
	    return valeurDeclare*0.1f;
	}else if(super.getTxRecommandation() == 2){
	    return valeurDeclare*0.5f;
	}else{
	    return 0;
	}
    }
    public float getTarifBase(){
	return tarifBase;
    }
    public String toString(){
	return "Colis " + super.toString()+"/"+super.getVolume()+"/"+valeurDeclare;
    }

    
}

package TP3;

public class Lettre extends ObjetPostal{

    private boolean urgente;
    private final float tarifBase = 0.5f;

    public Lettre(String origine,String destination,int codePostal,int poids,float volume,int txRecommandation,boolean urgente){
	super(origine,destination,codePostal,poids,volume,txRecommandation);
	this.urgente = urgente;
    }

    public float tarifAff(){
	float t = super.tarifAff();
	if(urgente){
	    return t+0.3f;
	}else{
	    return t;
	}
    } 
    public float tarifRemb(){
	if(super.getTxRecommandation() == 1){
	    return 1.5f;
	}else if(super.getTxRecommandation() == 2){
	    return 15;
	}else{
	    return 0;
	}
    }
    public float getTarifBase(){
	return tarifBase;
    }
    public String toString(){
	return "Lettre " + super.toString()+"/"+(urgente ? "Urgent" : "Ordinaire");
    }

    
}

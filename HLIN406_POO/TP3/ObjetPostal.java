package TP3;

public abstract class ObjetPostal{

    private String origine;
    private String destination;
    private int codePostal;
    private int poids;
    private float volume;
    private int txRecommandation;

    public ObjetPostal(String origine,String destination,int codePostal,int poids,float volume,int txRecommandation){
	this.origine = origine;
	this.destination = destination;
	this.codePostal = codePostal;
	this.poids = poids;
	this.volume = volume;
	if(txRecommandation>=0 && txRecommandation<=2){ 
	    this.txRecommandation = txRecommandation;
	}else{
	    System.out.println("Le taux de recommandation doit être entre 0 et 2, set sur 0 par defaut");
	    this.txRecommandation = 0;
	}
    }

    public float tarifAff(){
	float t = getTarifBase();
	if(txRecommandation == 1){
	    return t+0.5f;
	}else if(txRecommandation == 2){
	    return t+1.5f;
	}else{
	    return t;
	}
    }
    public abstract float tarifRemb();
    public void  affichage(){
	System.out.println(toString());
    }
    public abstract float getTarifBase();
    public int getTxRecommandation(){
	return txRecommandation;
    }
    public float getVolume(){
	return volume;
    }
    public int getPoids(){
	return poids;
    }
    public String toString(){
	return codePostal+"/"+destination+"/"+txRecommandation;
    }

    
}

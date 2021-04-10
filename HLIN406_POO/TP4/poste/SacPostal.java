package poste;
import java.util.ArrayList;

public class SacPostal{
    
    private ArrayList<ObjetPostal> collection;
    private float capacite = 0.5f;

    public SacPostal(){
	collection = new ArrayList<ObjetPostal>();
    }
    public SacPostal(float capacite){
	collection = new ArrayList<ObjetPostal>();
	this.capacite = capacite;
    }

    public ArrayList<ObjetPostal> getCollection(){
	return collection;
    }

    public float volume(){
	float volume = 0;
	for(ObjetPostal o : collection){
	    volume += o.getVolume();
	}
	return volume;
    }
    
    public void ajouter(ObjetPostal obj){
	if(volume()+obj.getVolume() <= capacite){
	    collection.add(obj);
	}else{
	    System.out.println("Votre objet est trop volumineux !");
	}
    }

    public float valeurRemb(){
	float val = 0;
	for(ObjetPostal o : collection){
	    val += o.tarifRemb();
	}
	return val;
    }

    public void remplir(SacPostal s, int CP){
	for(ObjetPostal o : s.getCollection()){
	    if(o.getCodePostal() == CP){
		ajouter(o);
	    }
	}
    }
    
    public void affiche(){
	System.out.println("Contenu : ");
	for(ObjetPostal o : collection){
	    o.affichage();
	}	
    }
}

package etudes;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Promotion{

    private ArrayList<Etudiant> collection;
    private int annee;

    public Promotion(){
	collection = new ArrayList<Etudiant>();
    }
    public Promotion(int annee){
	collection = new ArrayList<Etudiant>();
	this.annee = annee;
    }
    public ArrayList<Etudiant> getCollection(){
	return collection;
    }
    public int getAnnee(){
	return annee;
    }
    public void setAnnee(int annee){
	this.annee = annee;
    }
    public Etudiant getEtudiant(int i){
	return collection.get(i);
    }
    public int nbEtudiant(){
	return collection.size();
    }
    public void inscrire(Etudiant e){
	collection.add(e);
    }
    public float moyenneGenerale(){
	float moy = 0;
	for(Etudiant e : collection){
	    moy += e.moyenne();
	}
	moy /= collection.size();
	return moy;
    }
    public void afficheResultats(){
	for(Etudiant e : collection){
	    e.ligneResultats();
	}
    }
    public Etudiant recherche(String nom){
	for(Etudiant e : collection){
	    if(e.getNom() == nom){return e;}
	}
	return null;
    }
    public ArrayList<Etudiant> admis(){

	ArrayList<Etudiant> admis = new ArrayList<Etudiant>();
	for(Etudiant e : collection){
	    if(e.mention()!=Mention.Ajourne){
		admis.add(e);
	    }
	}
	return admis;
	
    }
    public ArrayList<Etudiant> nouveauxInscritNonFrancophones(){
	
	ArrayList<Etudiant> l = new ArrayList<Etudiant>();
	for(Etudiant e : collection){
	    if(e.getCodePays() == CodePays.nonFrancophone && e.getPremierInsc() ==true){
		l.add(e);
	    }
	}
	return l;
    }
    public ArrayList<Etudiant> majors(){
    	ArrayList<Etudiant> majors = new ArrayList<Etudiant>();
    	for(Etudiant e : collection){
    		if(majors.size() == 0){
    			majors.add(e);
    		}else if(e.moyenne() > majors.get(0).moyenne()){
    			majors.clear();
    			majors.add(e);
    		}else if(e.moyenne() == majors.get(0).moyenne()){
    			majors.add(e);
    		}	    
    	}
	return majors;
    }
    public void histo(){
    	for(int i =10; i < 19;i++) {
    		System.out.print("["+i+"-"+(i+1)+"[ : ");
    		for(Etudiant e : admis()) {
    			if(e.moyenne()>=i && e.moyenne()<(i+1)) {
    				System.out.print("*");
    			}
    		}
    		System.out.println();
    	}
    	
    	System.out.print("[19-20] : ");
    	for(Etudiant e : admis()) {
			if(e.moyenne()>=19 && e.moyenne()<=20) {
				System.out.print("*");
			}
		}
    	System.out.println();
    }
    public ArrayList<Float> moyennePlusFrequente() {
    	HashMap<Float, Integer> hmap = new HashMap<Float, Integer>();
    	for(Etudiant e : collection) {
    		if(hmap.containsKey(e.moyenne())){
    			hmap.replace(e.moyenne(), hmap.get(e.moyenne())+1);
    		}else {
    			hmap.put(e.moyenne(), 1);
    		}
    	}
    	/////////////////////////
    	ArrayList<Float> moy = new ArrayList<Float>();
    	int nbMax = 0;
    	for(Map.Entry<Float, Integer> i : hmap.entrySet()) {
    		if(moy.size()==0) {
    			moy.add(i.getKey());
    			nbMax = i.getValue();
    		}else if(i.getValue() > nbMax) {
    			moy.clear();
    			moy.add( i.getKey());
    			nbMax = i.getValue();
    		}else if(i.getValue() == nbMax) {
    			moy.add(i.getKey());
    		}
    	}
    	return moy;
    }
    public int nbPersonneMoy(float moy){
    	int nb = 0;
    	for (Etudiant e : collection) {
			if(Math.round(e.moyenne()) == moy) {
				nb++;
			}
		}
    	return nb;
    }
}

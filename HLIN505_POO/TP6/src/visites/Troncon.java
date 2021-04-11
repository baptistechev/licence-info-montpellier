package visites;

import java.util.Vector;


public class Troncon {
	private Etape depart;
	private Etape arrivee;
	private int tempsTrajet;
	private Vector<String> rues;

	public Troncon(Etape depart, Etape arrivee, int tempsTrajet, Vector<String> rues) {
		this.depart = depart;
		this.arrivee = arrivee;
		this.tempsTrajet = tempsTrajet;
		this.rues=rues;
	}
	public Troncon(Etape depart, Etape arrivee, int tempsTrajet) {
		this.depart = depart;
		this.arrivee = arrivee;
		this.tempsTrajet = tempsTrajet;	
		this.rues = new Vector<>();
		rues.add(depart.getRue());
		rues.add(arrivee.getRue());
	}

	public int getTempsTrajet() {
		return tempsTrajet;
	}
	public void setTempsTrajet(int tempsTrajet) {
		this.tempsTrajet = tempsTrajet;
	}
	public Etape getDepart() {
		return depart;
	}
	public void setDepart(Etape depart) {
		this.depart = depart;
	}
	public Etape getArrivee() {
		return arrivee;
	}
	public void setArrivee(Etape arrivee) {
		this.arrivee = arrivee;
	}

	/***
	 *  vérifie que la première rue de rues est la rue de départ, et la dernière celle d'arrivée
	 * @return vrai ssi la première rue de rues est la rue de départ, et la dernière celle d'arrivée
	 */
	public boolean verif(){
		boolean result;
		System.out.println(depart.getRue());
		System.out.println(rues.firstElement());
		System.out.println(arrivee.getRue());
		System.out.println(rues.lastElement());
		result=depart.getRue()==rues.firstElement();
		result=result&&arrivee.getRue()==rues.lastElement(); 
		return result;
	}

	/**
	 * vérifie que les noms des rues sont 2 à 2 différentes
	 * @return vrai ssi les noms de rues sont 2 à 2 différentes
	 */
	public boolean verifListeRues(){
		for (int i = 0; i < rues.size()-1; i++) {
			if(rues.get(i).equals(rues.get(i+1)))
				return false;
		}
		return true;
	}

}

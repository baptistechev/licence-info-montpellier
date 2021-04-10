package poste;

public class test{
    public static void main(String[] a){
	SacPostal s1 = new SacPostal();
	s1.ajouter(new Lettre("Montpellier","Paris",34000,200,0.1f,1,true));
	s1.ajouter(new Lettre("Montpellier","Londres",28000,200,0.1f,1,true));
	s1.ajouter(new Colis("Montpellier","Paris",34000,200,0.2f,1,"Objet Fragile",10));	
	s1.affiche();
	SacPostal s2 = new SacPostal();
	s2.remplir(s1,34000);
	s2.affiche();
	
	
    }
}

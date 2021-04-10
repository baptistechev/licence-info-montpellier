package TP3;

import java.time.LocalDate;

public class test{
    public static void main(String[] a){
	Lettre l = new Lettre("Montpellier","Paris",34000,200,0.1f,1,true);
	l.affichage();
	System.out.println("Tarif d'Affranchissement : " + l.tarifAff());
	ColisExpress ce1 = new ColisExpress("Montpellier","Paris",75000,300,1,2,"Appareil Electroniques 1",30,LocalDate.of(2020,12,10),true);
	ColisExpress ce2 = new ColisExpress("Montpellier","Paris",75000,300,1,2,"Appareil Electroniques 2",30,LocalDate.of(2020,12,10),true);
	ce1.affichage();
	ce2.affichage();
	System.out.println("Tarif d'Affranchissement : " + ce1.tarifAff());
    }
}

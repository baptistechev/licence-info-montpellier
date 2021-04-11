package pkg1;

import java.time.LocalDate;

public class Adherent {

	private String nom;
	private int numero;
	private static int nbAdherent = 0;
	
	private boolean cotisationPayee;
	private int date;
	
	public Adherent(String nom) {
		this.nbAdherent++;
		this.nom = nom;
		this.numero = nbAdherent;
		this.cotisationPayee = true;
		this.date = LocalDate.now().getYear();
	}
	
	public void reAdhesion(Adherent ad){
		ad.cotisationPayee = true;
		ad.date = LocalDate.now().getYear();
	}

	@Override
	public String toString() {
		return "Adherent [nom=" + nom + ", numéro=" + numero + ", cotisationPayee=" + cotisationPayee + ", date=" + date
				+ "]";
	}
	
	
}

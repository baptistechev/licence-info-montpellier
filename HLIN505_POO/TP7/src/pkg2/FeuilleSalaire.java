package pkg2;

import java.util.Iterator;


public class FeuilleSalaire implements Iterable<Object>{

	public enum TypePrelevement{
		CRDS, CSG, cotisationSalariales
	}
	
	private String employer;
	private String salarie;
	private String convention;
	private int nbHeure;
	private TypePrelevement prelevement;
	private int payeNet;
	
	public FeuilleSalaire(String employer, String salarie, String convention, int nbHeure, TypePrelevement prelevement,
			int payeNet) {
		super();
		this.employer = employer;
		this.salarie = salarie;
		this.convention = convention;
		this.nbHeure = nbHeure;
		this.prelevement = prelevement;
		this.payeNet = payeNet;
	}




	public String getEmployer() {
		return employer;
	}




	public String getSalarie() {
		return salarie;
	}




	public String getConvention() {
		return convention;
	}




	public int getNbHeure() {
		return nbHeure;
	}




	public TypePrelevement getPrelevement() {
		return prelevement;
	}




	public int getPayeNet() {
		return payeNet;
	}




	@Override
	public Iterator<Object> iterator() {
		return new iterateurFeuilleSalaire(this);
	}




	@Override
	public String toString() {
		return "FeuilleSalaire [employer=" + employer + ", salarie=" + salarie + ", convention=" + convention
				+ ", nbHeure=" + nbHeure + ", prelevement=" + prelevement + ", payeNet=" + payeNet + "]";
	}

	
	
}

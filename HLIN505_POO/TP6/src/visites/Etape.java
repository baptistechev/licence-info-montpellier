package visites;

public class Etape {
	private int dureeVisite;
	private NatureEtape type;
	private String nom;
	private String rue;
	
	public Etape(String nom, String rue, int dureeVisite, NatureEtape type) {
		this.nom=nom;
		this.rue=rue;
		this.dureeVisite = dureeVisite;
		this.type = type;
	}
	
	public NatureEtape getType() {
		return type;
	}

	public void setType(NatureEtape type) {
		this.type = type;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public int getDureeVisite() {
		return dureeVisite;
	}

	public void setDureeVisite(int dureeVisite) {
		this.dureeVisite = dureeVisite;
	}
	
	public String getRue() {
		return rue;
	}
/** 
 * v�rifie que l'�tape est correcte, c'est � dire que la dur�e de visite n'est nulle que s'il s'agit d'un lieu d'int�r�t sans visite.
 * @return vrai ssi duree de visite nulle <=> lieu d'int�r�t sans visite 
 */
	public boolean estCorrecte(){
		return ((dureeVisite==0&&type==NatureEtape.lieuInteretSansVisite) 
				
				);
	}
}

package biblio;

public class Contribution {
	private NatureCtr nature;
	private Notice notice;
	private Contributeur contributeur;
	
	public Contribution(NatureCtr nature, Notice notice, Contributeur contributeur) {
		this.nature = nature;
		this.notice = notice;
		this.contributeur = contributeur;
	}

	@Override
	public String toString() {
		return "Contribution [nature=" + nature + ", notice=" + notice + ", contributeur=" + contributeur + "]";
	}

	public Notice getNotice() {
		return notice;
	}

	public Contributeur getContributeur() {
		return contributeur;
	}
	
	
	
}

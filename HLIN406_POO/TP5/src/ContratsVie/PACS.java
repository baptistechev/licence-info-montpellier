package ContratsVie;

public class PACS extends ContratVieCommune{
	private Organisme tribunal;

	public PACS(int dateD, Organisme tribunal) {
		super(dateD);
		this.tribunal = tribunal;
	}
	
	@Override
	public String toString() {
		return "PACS [ "+super.toString()+" tribunal=" + tribunal + "]";
	}
}

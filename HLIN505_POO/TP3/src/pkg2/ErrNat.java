package pkg2;

public class ErrNat extends Exception{
	
	private int ErrVal;
	
	public ErrNat(int ErrVal) {
		// TODO Auto-generated constructor stub
		super();
		this.ErrVal = ErrVal;
	}
	
	public ErrNat(String msg, int ErrVal) {
		// TODO Auto-generated constructor stub
		super(msg);
		this.ErrVal = ErrVal;
	}
	
	public int getErrVal() {
		return this.ErrVal;
	}
}

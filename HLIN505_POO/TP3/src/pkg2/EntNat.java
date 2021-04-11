package pkg2;

public class EntNat {

	private int value;
	
	public EntNat(int n) throws ErrConst{
		// TODO Auto-generated constructor stub
//		try {
//			if(n<0) throw new ErrConst(n);
//			this.value = n;
//		}
//		catch(ErrConst e) {
//			System.out.println(e.getErrVal());
//		}
		if(n<0) throw new ErrConst(n);
		this.value = n;
	}
	
	public int getValue() {
		return this.value;
	}
	
	public void setValue(int n) throws ErrModif{
		if(n<0) throw new ErrModif(n);
		this.value = n;
	}
	
	public void decremente() throws ErrModif{
		if(this.value-1 < 0) throw new ErrModif(this.value-1);
		this.value--;
	}
	
	public static void decremente(EntNat e) throws ErrModif {
		e.decremente();
	}
}

package pkg5;

public class Paire <A,B>{
	
	private A fst;
	private B snd;
	public Paire() {}
	public Paire(A f, B s) {
		this.fst = f;
		this.snd = s;
	}
	public A getFst() {
		return fst;
	}
	public void setFst(A fst) {
		this.fst = fst;
	}
	public B getSnd() {
		return snd;
	}
	public void setSnd(B snd) {
		this.snd = snd;
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return getFst()+"-"+getSnd();
	}
}

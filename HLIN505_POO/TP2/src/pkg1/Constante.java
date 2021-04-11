package pkg1;

public class Constante extends Expression{
	
	private float value;
	
	public Constante(float value) {
		this.value = value;
		// TODO Auto-generated constructor stub
	}
	
	public float eval() {
		return value;
	}
	
	@Override
	public String toString() {
		return this.value+"";
	}
	
}

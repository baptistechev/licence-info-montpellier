package pkg1;

public abstract class Expression{
	
	public abstract float eval();
	
	public boolean equals(Object obj) {
		if(obj instanceof Expression)
			return (this.eval() == ((Expression)obj).eval());
		else
			return false;
	}
	
}

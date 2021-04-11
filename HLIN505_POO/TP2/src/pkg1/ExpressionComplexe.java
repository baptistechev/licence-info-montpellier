package pkg1;

public class ExpressionComplexe extends Expression{
	private Expression a, b;
	private char op;
	
	public ExpressionComplexe(Expression a, char op, Expression b) {
		super();
		this.a = a;
		this.b = b;
		if(op == '+' || op == '-' || op=='*' || op=='/')
			this.op = op;
		else
			this.op = '?';
	}
	
	public float eval() {
		switch(op){
		case '+':
			return a.eval() + b.eval();
		case '-':
			return a.eval() - b.eval(); 
		case '*':
			return a.eval() * b.eval();
		case '/':
			return a.eval() / b.eval();
		default:
			System.out.println("L'expression n'est pas évaluable !!");
			return -9999;
		}
	}
	
	@Override
	public String toString() {
		return "("+a.toString()+") "+op+" ("+b.toString()+")";
	}	
	
}

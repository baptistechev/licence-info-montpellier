package pkg1;

import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		
		Constante a = new Constante(5);
		Constante b = new Constante(2);
		Constante c = new Constante(3);
		ExpressionComplexe  e1 = new ExpressionComplexe(a,'+',b);
		ExpressionComplexe  e2 = new ExpressionComplexe(e1,'*',c);
		ExpressionComplexe  e3 = new ExpressionComplexe(new Constante(4),'*',e2);
		
		System.out.println(e1);
		System.out.println(e2);
		System.out.println(e3);
		System.out.println(a.eval()); //  5.0
		System.out.println(e1.eval()); //  7.0
		System.out.println(e2.eval()); //  21.0
		System.out.println(e3.eval()); //  84.0
		
		Object e4=new Constante(84);
		System.out.println(e3.equals(e4));// true
		ArrayList<Expression>liste=new ArrayList<>();
		liste.add(e3);
		System.out.println(liste.contains(new Constante (84)));//true
	}

}

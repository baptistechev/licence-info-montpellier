package pkg1;

import java.lang.reflect.Method;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		class1 c = new class1();
		
		Method[] meths = c.getMethods(1);

		
		System.out.println(c.getClassCommune());
	}

}

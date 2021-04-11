package pkg2;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class methodInvoquer {

	public void invoque(String methodName, Object o) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException, MethodeInexistanteException {
		
		Class c = o.getClass();
		Method[] meths = c.getDeclaredMethods();
		boolean found = false;;
		
		while(c != null) {
			for (Method m : meths) {
				if(m.getName() == methodName) {
					if(m.isAccessible())
						m.invoke(o);
					else {
						m.setAccessible(true);
						m.invoke(o);
						m.setAccessible(false);
					}
					found = true;
				}
					
			}
			c = c.getSuperclass();
		}
		if(!found)
			throw new MethodeInexistanteException();
		
			
		
	}
	
}

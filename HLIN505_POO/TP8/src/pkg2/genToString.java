package pkg2;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;

public class genToString {

	private String indent(int i) {
		String str ="";
		for (int j = 0; j < i; j++) {
			str += " ";
		}
		return str;
	}
	
	public String toString(Object o, int indent) throws IllegalArgumentException, IllegalAccessException, InstantiationException, InvocationTargetException, SecurityException {
		
		String str = "";

			
		Field[] fields = o.getClass().getDeclaredFields();
		
		for (Field f : fields) {
			f.setAccessible(true);
			
			if(f.getType() != int.class && f.getType() != boolean.class && f.getType() != java.lang.String.class && f.get(o) != null) {
				Class c = f.getType();
				try {
					Constructor cons = c.getConstructor();
					str += indent(indent) + f.getName() + " : \n" + toString(cons.newInstance(), indent+4);
				}catch(Exception e) {
					str += indent(indent) + f.getName() + " : " + "\n";
				}
			}else {
				str += indent(indent) + f.getName() + " : " + f.get(o) + "\n";
			}
			
			f.setAccessible(false);
		}
		
		return str;
	}
	
public String toString(Object o, int indent, int prof) throws IllegalArgumentException, IllegalAccessException, InstantiationException, InvocationTargetException, SecurityException {
		
		if(prof == 0)
			return "";
		String str = "";

			
		Field[] fields = o.getClass().getDeclaredFields();
		
		for (Field f : fields) {
			f.setAccessible(true);
			
			if(f.getType() != int.class && f.getType() != boolean.class && f.getType() != java.lang.String.class && f.get(o) != null) {
				Class c = f.getType();
				try {
					Constructor cons = c.getConstructor();
					str += indent(indent) + f.getName() + " : \n" + toString(cons.newInstance(), indent+4, prof-1);
				}catch(Exception e) {
					str += indent(indent) + f.getName() + " : " + "\n";
				}
			}else {
				str += indent(indent) + f.getName() + " : " + f.get(o) + "\n";
			}
			
			f.setAccessible(false);
		}
		
		return str;
	}
	
}

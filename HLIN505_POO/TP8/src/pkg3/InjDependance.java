package pkg3;

import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;

public class InjDependance {
	
	public void InjDep(Object o) throws IllegalArgumentException, IllegalAccessException, InstantiationException, InvocationTargetException, NoSuchMethodException, SecurityException {
		
		for(Field f : o.getClass().getFields()) {
			if(f.isAnnotationPresent(InjectMe.class)) {
				Class c = f.getType();
				f.set(o, c.getConstructor().newInstance());
			}
		}
		
	}
	
}

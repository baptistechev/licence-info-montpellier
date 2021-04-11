package pkg2;

import java.lang.annotation.*;
import java.lang.reflect.*;
import java.util.ArrayList;

public class AnnotationManager {

	ArrayList<Class> classList;
	
	public AnnotationManager() {
		// TODO Auto-generated constructor stub
		classList = new ArrayList<>();
		classList.add(pkg2.Personnage.class);
		classList.add(pkg2.PersonnageBonus.class);
		classList.add(pkg2.PersonnageInvisible.class);
	}
	
	public void listToDo() {
		for (Class c : classList) {
		
			Method[] meths = c.getDeclaredMethods();
			for (Method m : meths) {
				if(m.isAnnotationPresent(Todo.class)) {
					System.out.println(m.getName() +" : "+ m.getAnnotation(Todo.class));
				}
			}
			
		}
	}
	
	
	public void listToDo(TacheType t) {
		for (Class c : classList) {
			
			Method[] meths = c.getDeclaredMethods();
			for (Method m : meths) {
				if(m.isAnnotationPresent(Todo.class) && m.getAnnotation(Todo.class).type() == t) {
					System.out.println(m.getName() +" : "+ m.getAnnotation(Todo.class));
				}
			}
			
		}
	}
	
	public int dureeTotal(int version) {
		int tot = 0;
		for (Class c : classList) {
					
					Method[] meths = c.getDeclaredMethods();
					for (Method m : meths) {
						if(m.isAnnotationPresent(Todo.class) && m.getAnnotation(Todo.class).numVersion() == version) {
							tot += m.getAnnotation(Todo.class).duree();
						}
					}
					
				}
		return tot;
	}
}

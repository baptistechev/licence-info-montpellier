package pkg1;

import java.lang.reflect.Method;
import java.util.ArrayList;

public class class1 {

	private ArrayList<Object> list;
	
	public class1() {
		// TODO Auto-generated constructor stub
		this.list = new ArrayList<>();
		this.remplir();
	}
	
	private void remplir() {
//		this.list.add("str");
		this.list.add(2);
//		this.list.add(new Double(0.0));
		this.list.add(3);
	}
	
	public Method[] getMethods(int i) {
		//retourne les methodes de list[i]
		
		return this.list.get(i).getClass().getMethods();
		
	}
	
	public Class getClassCommune() {
		Class c = list.get(0).getClass();
		ArrayList<Class> classList = new ArrayList<>();
		while(c!=null) {
			classList.add(c);
			c = c.getSuperclass();
		}
		c = classList.get(0);
		
		for (Object o : list) {			
			Class co = o.getClass();
			if(c != co) {
				
				while(!classList.contains(co)) {
					co = co.getSuperclass();
					if(co == null) {
						System.out.println("pas de class commune");
						return null;
					}
				}
				while(c!=co) {
					classList.remove(c);
					c = c.getSuperclass();
				}
			}
		}
		return c;
	}
	
}

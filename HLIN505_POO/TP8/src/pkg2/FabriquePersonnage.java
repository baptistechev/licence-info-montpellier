package pkg2;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.util.Scanner;

public class FabriquePersonnage {

	public Personnage createPerso(String className) throws ClassNotFoundException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, NoSuchMethodException, SecurityException {

		return (Personnage) Class.forName(className).getConstructor().newInstance();
	}
	
	public void changeAttr(Personnage p) throws IllegalArgumentException, IllegalAccessException {
		Scanner sc = new Scanner(System.in);
		String str;
		int i;
				
		for (Field f : p.getClass().getSuperclass().getDeclaredFields()){
			System.out.println("Donnez une valeur pour " + f.getName());
			f.setAccessible(true);
			
			if(f.getType().getName() == "int") {
				i = sc.nextInt();
				f.set(p, i);
			}else {
				str = sc.nextLine();
				f.set(p, str);
			}
			
			
			f.setAccessible(false);

		}
		for (Field f : p.getClass().getDeclaredFields()){
			if(f.getName() == "isInvisible") {
				System.out.println("Donnez une valeur pour " + f.getName());
				f.setAccessible(true);
				
				boolean b = sc.nextBoolean();
				f.set(p, b);
				
				f.setAccessible(false);
			}
		}
		
		sc.close();
	}
	
	public void changeAttrDyn(Personnage p) {
		p.changeAttr();
	}
	
	public Personnage convert(Personnage p, String className) throws ClassNotFoundException, NoSuchMethodException, SecurityException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
//		Class c = Class.forName(className);
//		
//		Constructor cons = c.getSuperclass().getConstructor(String.class, int.class, int.class);
//		
//		Personnage perso = (Personnage) cons.newInstance(p.getNom(), p.getNbPoints(), p.getNbVies());
		
		Personnage perso = createPerso(className);
		perso.setNom(p.getNom());
		perso.setNbPoints(p.getNbPoints());
		perso.setNbVies(p.getNbVies());
		
		Scanner sc = new Scanner(System.in);
		for (Field f : perso.getClass().getDeclaredFields()){
			if(f.getName() == "isInvisible") {
				System.out.println("Donnez une valeur pour " + f.getName());
				f.setAccessible(true);
				
				boolean b = sc.nextBoolean();
				f.set(perso, b);
				
				f.setAccessible(false);
			}
		}
		
		return perso;
	}
	
}

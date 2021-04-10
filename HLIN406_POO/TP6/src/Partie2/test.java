package Partie2;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class test {	
	
	public static<E extends Comparable<E>> E max(List<E> c)
	{
	if (c.isEmpty())
	return null;
	E max = c.get(0);
	for (E e : c)
	if (e.compareTo(max)>0)
	max = e;
	return max;
	}

	public static void main(String[] args) {
		ArrayList<Integer> listeEntiers = new ArrayList<Integer>();
		listeEntiers.add(4); listeEntiers.add(8);
		System.out.println(max(listeEntiers));
		LinkedList<String> listeChaines = new LinkedList<String>();
		listeChaines.add("galette");
		listeChaines.add("crepes");
		listeChaines.add("bugnes");
		System.out.println(max(listeChaines));
		
		Personne p1 = new Personne("Jean", "Boris");
		Personne p2 = new Personne("Jean", "Sebastien");
		Personne p3 = new Personne("Benoit", "Delacour");
		ArrayList<Personne> listePersonnes = new ArrayList<Personne>();
		
		listePersonnes.add(p1);
		listePersonnes.add(p2);
		listePersonnes.add(p3);
		System.out.println(max(listePersonnes));
	}

}

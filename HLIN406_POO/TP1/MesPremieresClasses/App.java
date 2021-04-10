package MesPremieresClasses;

import java.util.Scanner;

public class App {
    public static void main(String[] a) throws java.io.IOException{
	Scanner sc = new Scanner(System.in);

	int e1,e2;
	float f1,f2;

	System.out.print("Saisir 2 entiers :");
	e1 = sc.nextInt();
	e2 = sc.nextInt();
	System.out.print("Saisir 2 flotants :");
	f1 = sc.nextFloat();
	f2 = sc.nextFloat();

	System.out.println(e1+"/"+e2+" = "+e1/e2);
	System.out.println(f1+"/"+f2+" = "+f1/f2);
    }
}

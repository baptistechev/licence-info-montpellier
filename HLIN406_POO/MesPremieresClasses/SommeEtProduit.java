package MesPremieresClasses;

import java.util.Scanner;

public class SommeEtProduit {
  public static void main(String[] a) throws java.io.IOException
  {
      Scanner sc = new Scanner(System.in);

      double x, y;
      //System.out.println("entrez deux doubles ");
      x = Double.valueOf(a[0]);
      y = Double.valueOf(a[1]);
      double somme = x+y;
      double produit = x*y;
      System.out.println("somme = "+somme+" produit = "+produit);
   }

}

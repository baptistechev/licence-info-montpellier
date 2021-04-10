package quincaillerie;

import java.util.ArrayList;
import java.util.Scanner;

public class Portail {

	private GestionClients gestionClients;
	private Vente vente;
	private Panier panierCourant;
	private ArrayList<Panier> paniers;
	private ArrayList<Piece> catalogue;
	
	public Portail() {
		gestionClients = new GestionClients();
		paniers = new ArrayList<Panier>();
		catalogue = new ArrayList<Piece>();
	}

	public Panier getPanierCourant() {
		return panierCourant;
	}
	
	public void initCatalogue() {
		Scanner sc = new Scanner(System.in);
		int choix;
		do {
			System.out.println("Bienvenue sur le menu d'édition du Catalogue !\n"
								+"------------------------------------------------\n"
								+"1-Ajouter une nouvelle piece\n"
								+"2-Valider\n"
								+"------------------------------------------------");
			choix = sc.nextInt();
			switch (choix) {
			case 1:
				int choix2;
				do {
					System.out.println("Quel type de piece voulez-vous ?\n"
										+"--------------------------------\n"
										+"1-Piece de Base\n"
										+"2-Piece composite en Kit\n"
										+"3-Piece composite Montée\n"
										+"(0 to exit)\n");
					choix2 = sc.nextInt();
					switch(choix2) {
					case 1:
						System.out.println("Nom? Ref? Prix? Garantie? Fabrication?");
						sc.nextLine();
						String nom = sc.nextLine();
						String ref = sc.nextLine();
						float prix = sc.nextFloat();
						int garantie = sc.nextInt();
						int dfab = sc.nextInt();
						catalogue.add(new PieceDeBase(nom, ref, prix, garantie, dfab));
						afficherCatalogue();
						choix2 = 0;
						break;
					case 2:
						System.out.println("Nom? Ref? Temps montage?");
						sc.nextLine();
						String nom2 = sc.nextLine();
						String ref2 = sc.nextLine();
						int	tpsMont = sc.nextInt();
						PieceCompositeEnKit piece = new PieceCompositeEnKit(nom2, ref2, tpsMont);
						catalogue.add(piece);
						System.out.println("Dépendances ? ('exit' to exit)");
						String choix3;
						do {
							choix3 = sc.nextLine();
							for (Piece p : catalogue) {
								if(p.getNom()==choix3) {
									piece.ajoute(p);
								}
							}
						}while(!choix3.contains("exit"));
						choix2 = 0;
						break;
					case 3:
						System.out.println("Nom? Ref? Prix Montage ? Temps montage?");
						sc.nextLine();
						String nom3 = sc.nextLine();
						String ref3 = sc.nextLine();
						float prixMont = sc.nextFloat();
						int	tpsMont2 = sc.nextInt();
						PieceCompositeMonte piece2 = new PieceCompositeMonte(nom3, ref3, prixMont, tpsMont2);
						catalogue.add(piece2);
						System.out.println("Dépendances ? ('exit' to exit)");
						String choix4;
						do {
							choix4 = sc.nextLine();
							for (Piece p : catalogue) {
								if(p.getNom()==choix4) {
									piece2.ajoute(p);
								}
							}
						}while(!choix4.contains("exit"));
						choix2 = 0;
						break;
					default:
						System.out.println("Choix indisponible !");
					}
				}while(choix2!=0);
				break;
			case 2:
				System.out.println("Vous avez validé le catalogue avec les articles suivant :\n");
				afficherCatalogue();
				break;
			default:
				System.out.println("Choix indisponible !");
			}
		}while(choix!=2);
	}
	
	public void addCatalogue(Piece p) {
		catalogue.add(p);
	}
	
	public void afficherCatalogue() {
		for (Piece p : catalogue) {
			System.out.println(p+"\n-------------------------------------------\n");
		}
	}
	
	public Piece chercherPiece(String ref) {
		for (Piece p : catalogue) {
			if(p.getRef().equalsIgnoreCase(ref))
				return p;
		}
		return null;
	}
	
	public void validerPanier() {
		panierCourant.Valider();
	}
	
	public void decrementerQuantitePiece(Piece p) {
		panierCourant.decrementerQuantite(p);
	}
	
	public void incrementerQuantitePiece(Piece p) {
		panierCourant.incrementerQuantite(p);
	}
	
	public void ajouterPiecePanier(Piece p) {
		if(catalogue.contains(p))
			panierCourant.ajouterPanier(p);
		else
			System.out.println("La piece n'est pas dans le catalogue !");
	}
	
	public void retirerPiecePanier(Piece p) {
		panierCourant.retirerPanier(p);
	}
	
	public void affichagePanier() {
		System.out.println(panierCourant);
	}
	
	public void nouveauPanierCourant() {
		if(panierCourant!=null)
			paniers.add(panierCourant);
		panierCourant = new Panier();
	}

	public GestionClients getGestionClients() {
		return gestionClients;
	}
	
}

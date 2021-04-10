package quincaillerie;

import java.util.Scanner;

public class test {

	public static void main(String[] args) {


		PieceCompositeEnKit p = new PieceCompositeEnKit("Roue de brouette", "1512", 15);
		p.ajoute(new PieceDeBase("pneu", "4567", 8, 40, 1));
		p.ajoute(new PieceDeBase("chambre a air", "0359", 6, 200, 4));

		PieceCompositeEnKit p1 = new PieceCompositeEnKit("jante", "9840", 10);
		p1.ajoute(new PieceDeBase("disque de jante", "4855", 4, 40, 2));
		PieceDeBase rayon = new PieceDeBase("rayon", "4958", 2, 130, 1);
		p1.ajoute(rayon);
		p1.ajoute(rayon);
		p1.ajoute(rayon);
		
		p.ajoute(p1);

		PieceCompositeMonte p2 = new PieceCompositeMonte("Roue de brouette", "1512", 15, 1);
		p2.ajoute(new PieceDeBase("pneu", "4567", 8, 40, 1));
		p2.ajoute(new PieceDeBase("chambre a air", "0359", 6, 200, 4));
		
		PieceCompositeMonte p3 = new PieceCompositeMonte("jante", "9840", 4,10);
		p3.ajoute(new PieceDeBase("disque de jante", "4855", 4, 40, 2));
		p3.ajoute(rayon);
		p3.ajoute(rayon);
		p3.ajoute(rayon);
		
		p2.ajoute(p3);
//		
//		p.affiche();
//		System.out.println("---------------------------------------------\n");
//		p2.affiche();
		
//		Panier pan = new Panier();
//		
//		pan.ajouterPanier(p);
//		pan.incrementerQuantite(p);
//		pan.incrementerQuantite(p1);
//		System.out.println(pan);
		
		Portail po = new Portail();
		po.addCatalogue(new PieceDeBase("pneu", "4567", 8, 40, 1));
		po.addCatalogue(new PieceDeBase("chambre a air", "0359", 6, 200, 4));
		po.addCatalogue(new PieceDeBase("disque de jante", "4855", 4, 40, 2));
		po.addCatalogue(new PieceDeBase("rayon", "4958", 2, 130, 1));
		po.addCatalogue(p);
		po.addCatalogue(p1);
		po.addCatalogue(p2);
		po.addCatalogue(p3);

		po.getGestionClients().nouveauParticulier("Jean", "5 rue", "jean@gmail.com", "boris", Civilite.M, Sexe.HOMME);
		po.getGestionClients().getClient("jean@gmail.com").getCarteFidelite().nouvelAchat(100000);
		Scanner sc = new Scanner(System.in);
		
		while(true) {
			System.out.println("Bienvenue ! ");
			po.nouveauPanierCourant();
			int choix;
			do {
				System.out.println("-------------Menu---------------\n"
						+"1-Afficher le panier\n"
						+"2-ajouter une piece au panier\n"
						+"3-retirer une piece du panier\n"
						+"4-incrementer quantité d'un piece\n"
						+"5-décrementer quantité d'un piece\n"
						+"6-valider le panier\n");
				choix = sc.nextInt();
				switch (choix) {
				case 1:
					po.affichagePanier();
					break;
				case 2:
					po.afficherCatalogue();
					System.out.println("Sélectionnez une piece dans le catalogue :");
					sc.nextLine();
					String ref = sc.nextLine();
					if(po.chercherPiece(ref)!=null)
						po.ajouterPiecePanier(po.chercherPiece(ref));
					else
						System.out.println("La piece n'est pas dans le catalogue !");
					break;
				case 3:
					po.affichagePanier();
					System.out.println("Sélectionnez une piece à retirer :");
					sc.nextLine();
					String ref2 = sc.nextLine();
					ElementPanier ep = po.getPanierCourant().recherchePiece(ref2);
					if(ep!=null)
						po.retirerPiecePanier(ep.getPiece());
					break;
				case 4:
					po.affichagePanier();
					System.out.println("Sélectionnez une piece pour incrementer la quantitée :");
					sc.nextLine();
					String ref3 = sc.nextLine();
					ElementPanier ep1 = po.getPanierCourant().recherchePiece(ref3);
					if(ep1!=null)
						po.incrementerQuantitePiece(ep1.getPiece());
					break;
				case 5:
					po.affichagePanier();
					System.out.println("Sélectionnez une piece pour décrémenter la quantitée :");
					sc.nextLine();
					String ref4 = sc.nextLine();
					ElementPanier ep2 = po.getPanierCourant().recherchePiece(ref4);
					if(ep2!=null)
						po.decrementerQuantitePiece(ep2.getPiece());
					break;
				case 6:
					po.validerPanier();
					choix  = 0;
					break;
				}
			}while(choix!=0);
			
			System.out.println("Entrez votre email : ");
			sc.nextLine();
			String mail = sc.nextLine();
			if(po.getGestionClients().getClient(mail) == null) {
				System.out.println("Enregistrez vous en tant que nouveau client ! Etes vous :\n1-Entreprise\n2-Parituclier\n");
				int choix2;
				do {
					choix2 = sc.nextInt();
					switch (choix2) {
					case 1:
						System.out.println("Entrez les infos suivantes : nom,adresse postale et numéro SIRET \n");
						sc.nextLine();
						String name = sc.nextLine();
						String adressePost = sc.nextLine();
						String sIRET = sc.nextLine();
						po.getGestionClients().nouvelEntreprise(name, adressePost, mail, sIRET);
						choix2 = 0;
						break;
					case 2:
						System.out.println("Entrez les infos suivantes : nom,adresse postale, prenom,civilité et Sexe \n");
						sc.nextLine();
						String name1 = sc.nextLine();
						String adressePost1 = sc.nextLine();
						String prenom = sc.nextLine();
						Civilite civilité = (sc.nextLine().equalsIgnoreCase("M"))?Civilite.M : Civilite.Mme;
						Sexe sexe = (sc.nextLine().equalsIgnoreCase("HOMME"))?Sexe.HOMME:Sexe.FEMME;
						po.getGestionClients().nouveauParticulier(name1, adressePost1, mail,prenom, civilité,sexe);
						choix2 = 0;
						break;
					}
				}while(choix2!=0);
				
			}
			Client client = po.getGestionClients().getClient(mail);
			System.out.println(client);
			System.out.println("Vous disposez de "+client.getCarteFidelite().getPoints()+" points de fidélité !");
			System.out.println("Prix total a payer : "+po.getPanierCourant().getPrix());
			System.out.println("Réduction possible : "+client.getCarteFidelite().calculReductionPossible());
			System.out.println("Nouveau prix : "+ (po.getPanierCourant().getPrix() - client.getCarteFidelite().calculReductionPossible()*po.getPanierCourant().getPrix()));
			System.out.println("Souhaitez vous utiliser vos points ?\n1-Oui\n2-Non");
			int choix3;
			float prixFinal;
			do {
				choix3 = sc.nextInt();
				switch (choix3) {
				case 1:
					prixFinal = po.getPanierCourant().getPrix() - client.getCarteFidelite().calculReductionPossible()*po.getPanierCourant().getPrix();
					client.getCarteFidelite().applicationReduction();
					choix3 = 0;
					break;
				case 2:
					prixFinal = po.getPanierCourant().getPrix();
					client.getCarteFidelite().nouvelAchat(prixFinal);
					choix3 = 0;
					break;
				}
			}while(choix3!=0);
			System.out.println("Paiment en cours... patientez");
			System.out.println("Le paiment a été effectué, votre nouveau solde de points est : "+client.getCarteFidelite().getPoints());
			System.out.println("Merci de votre achat ! A bientot !");
			
		}
	}
}

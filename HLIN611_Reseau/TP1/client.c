#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include<string.h>

#include "fonctions.c"

int main(int argc, char *argv[]) {

  /* je passe en paramètre l'adresse de la socket d'écoute du serveur
     (IP et numéro de port). Je teste donc le passage de parametres */

  if (argc != 3){
    printf("utilisation : %s ip_serveur port_serveur\n", argv[0]);
    exit(0);
  }
//   short port = atoi(argv[2]);
//   printf("%i\n",port);

  /* Etape 1 : créer une socket */   
  int ds = socket(PF_INET, SOCK_STREAM, 0);

  /* /!\ : Il est indispensable de tester les valeurs de retour de
     toutes les fonctions et agir en fonction des valeurs possibles.*/
  if (ds == -1){
    printf("Client : pb creation socket\n");
    exit(1); // je choisis ici d'arrêter le programme car le reste
	     // dépendent de la réussite de la création de la socket.
  }
  
  /* J'alimente le programme avec des traces d'exécution pour observer ce
     qui se produit à l'exécution et pour mieux localiser les erreurs. */
  printf("Client: creation de la socket : ok\n");
  
  // Je peux déjà tester l'exécution de cette étape avant de passer à la suite.
  
  /* Etape 2 : designer la socket du serveur : avoir une structure qui
     contient l'adresse de cette socket (IP + numéro de port. */
  struct sockaddr_in adrServ;
//   int res = inet_pton(AF_INET, argv[1], &(adrServ.sin_addr));
  adrServ.sin_addr.s_addr = inet_addr(argv[1]);
  adrServ.sin_family = AF_INET; // Une IP
  adrServ.sin_port = htons(atoi(argv[2])); //numéro de port
    
  int lgAdr = sizeof(struct sockaddr_in);

  /* Etape 3 : envoyer une demande de connexion au serveur.*/
  int conn = connect(ds, (struct sockaddr *) &adrServ, lgAdr);
  // je traite les valeurs de retour
  if (conn <0){
    perror ("Client: pb au connect :");
    close (ds); // je libère les ressources avant de terminer.
    exit (1); // je choisi de quitter le programme : la suite dépend
	      // de la réussite de l'envoi de la demande de connexion.
  }

  // je continue à alimenter le programme avec traces d'exécution
  printf("Client : demande de connexion reussie \n");

  // Je peux tester l'exécution de cette étape avant de passer à la suite.
  
  /* Etape 4 : envoyer un message au serveur. Ce message est une chaîne de caractères saisie au clavier. Vous pouvez utiliser une autre fonction pour la saisie. */

  printf("saisir un message à envoyer (moins de 200 caracteres) \n");
  char m[1500]; 
  fgets(m, sizeof(m), stdin); 
  
   int taille = strlen(m);
   int snd, res = 0, cpt = 0;

   while(1){
      snd = sendTCP(ds, m, taille, &res);
      if(snd<0){
         perror("Pb envoi message\n");
         close(ds);
         exit(1);
      }
      if(snd == 0){
         printf("Socket fermee");
         close(ds);  
      }
      cpt += res;
      printf("message envoyé \n");
   }

  printf("Client : nombres d'appels %d \n", cpt);

  close (ds);
  printf("Client : je termine\n");

}

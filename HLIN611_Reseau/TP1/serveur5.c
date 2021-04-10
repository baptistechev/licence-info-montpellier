#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.c"

// Rôle du serveur : accepter la demande de connexion d'un client,
// recevoir une chaîne de caractères, afficher cette chaîne et
// renvoyer au client le nombre d'octets reçus par le serveur.

int main(int argc, char *argv[])
{
  // je passe en paramètre un numero de port pour la socket
  // d'écoute. Je teste donc le passage de paramètres
  
  if (argc!=2){
    printf("utilisation: %s numero_port\n", argv[0]);
    exit(1);
  }
  
  /* Etape 1 : créer une socket (la socket qui permettra de recevoir
     les demandes de connexion.*/
 
  int ds = socket(PF_INET, SOCK_STREAM, 0);
  /* /!\ : Il est indispensable de tester les valeurs de retour de
     toutes les fonctions et agir en fonction des valeurs possibles.*/
  if (ds == -1){
    perror("Serveur : probleme creation socket");
    exit(1); // je choisis ici d'arrêter le programme car le reste
	     // dépendent de la réussite de la création de la socket.
  }
  

  // J'alimente le programme avec traces d'exécution pour observer ce
  // qui se produit à l'exécution et mieux localiser les erreurs. 
  printf("Serveur: creation de la socket : ok\n");


  // Je peux déjà tester l'exécution de cette étape avant de passer à la suite.
  
  /* Etape 2 : nommer la socket. Elle aura une ou des IP de la machine
     sur laquelle le programme sera exécuté et le numéro de port passé
     en paramètre*/

  
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(atoi(argv[1]));
  
  int lgAdr = sizeof(struct sockaddr_in);

  if(bind(ds, (struct sockaddr *) &server, lgAdr) < 0){
    perror("Serveur : erreur bind");
    close(ds); // je libère les ressources avant de terminer.
    exit(1); // je choisis de quitter le programme : la suite dépend de la réussite du nommage.
  }

  // je continue à alimenter le programme avec traces d'exécution
  printf("Serveur: nommage : ok\n");


  // Je peux tester l'exécution de cette étape avant de passer à la suite.


  /* Etape 3 : mise en ecoute de la socket nommée. Cette opération
     dédie la socket à la réception des demandes de connexion. Pour
     cet exercice, limiter la file des demandes de connexions à 5. */
  
  int ecoute = listen(ds, 10);
  if (ecoute < 0){
    printf("Serveur : je suis sourd(e)\n");
    close (ds);
    exit (1);
  } 
 
  // je continue à alimenter le programme avec traces d'exécution
  printf("Serveur: mise en écoute : ok\n");


  // Je peux tester l'exécution de cette étape avant de passer à la suite.

 
  /* etape 4 : attendre et traiter une demande de connexion d'un
     client. Rappel : lorsque le serveur accepte une demande de
     connexion, il crée une nouvelle socket. Cette dernière est
     connectée à celle du client et elle est à utiliser pour
     communiquer avec lui.*/

  // avant un appel à une fonction bloquante, il est intéressant
  // d'afficher un message le signalant. Vous saurez ainsi à quelle
  // étape de l'exécution le blocage se produit.
  printf("Serveur : j'attends la demande d'un client (accept) \n"); 
  
  struct sockaddr_in adCv ; // pour obtenir l'adresse du client accepté.
  socklen_t lgCv = sizeof(struct sockaddr_in);

  int dsCv = accept(ds, (struct sockaddr *) &adCv, &lgCv);
  if (dsCv < 0){ // je pense toujours à traiter les valeurs de retour.
    perror ( "Serveur, probleme accept :");
    close(ds);
    exit (1);
  }
  /* je peux afficher l'adresse de la socket du client accepté :
     adresse IP et numéro de port de la structure adCv. Attention à
     faire les conversions du format réseau vers le format
     hôte. Utiliser la fonction inet_ntoa(..) pour l'IP.*/
  printf("Serveur: le client %s:%d est connecté  \n", inet_ntoa(adCv.sin_addr),  ntohs(adCv.sin_port));

 
  char buffer[4000];

   int taille, res = 0;
   int rcv = recvTCP (dsCv, &taille, sizeof(int), &res);
    if(rcv<0){
     perror("Pb envoi message\n");
     close(dsCv);
     close(ds);
     exit(1);
   }
  if(rcv == 0){
      printf("Socket fermee");
      close(dsCv);  
   }
   int cpt = res;
  rcv = recvTCP (dsCv, buffer, 2*taille, &res);

 if(rcv<0){
     perror("Pb envoi message\n");
     close(dsCv);
     close(ds);
     exit(1);
  }
  if(rcv == 0){
      printf("Socket fermee");
      close(dsCv);  
   }
  buffer[2*taille] = '\0';
   cpt += res;
   printf("Serveur : nombres d'appels %d \n", cpt);
   printf("Serveur : contenu du message : %s \n", buffer);
    
  /* Etape 7 : fermeture de la socket du client */ 
  printf("Serveur : fin du dialogue avec le client\n");
  close (dsCv);
  
  // Etape 8 : pour cet exercice, je ne traite qu'un client, donc, je termine proprement.
  close (ds);
  printf("Serveur : je termine\n");
}









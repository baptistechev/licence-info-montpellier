#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/* Rôle du serveur (attention, se serveur ne traite qu'un client !) :
 -  accepter la demande de connexion d'un client ;

 - en boucle (infinie) : 1) recevoir un message de type "long int" ;
   2) comparer sa valeur avec la précédente reçue ; 3) si la valeur
   reçue est inférieure à la précédente, afficher une trace notifiant
   ce cas; 4) dans tous les cas, afficher le nombre total d'octets
   reçus depuis le début et le nombre d'appels à la fonction recv(...)

 - termine apres départ du client.

*/


/* Réutiliser les fonctions de l'exercice 3 du TP précédent */
/* les deux derniers parametres sont les compteurs, auxquels doit s'ajouter le nombre d'octets
   lus depuis le buffer de réception et le nombre d'appels reussis à recv(..)
   (ils sont initialisés par l'appelant.*/
/* Si vous avez utilisé des variables globales, pas de souci. */
int recvTCP(int socket, char *buffer, size_t length, unsigned int *nbBytesReceved, unsigned int * nbCallRecv){

  // ce squelette est juste pour vous indiquer où et comment utiliser
  // les paramètres en plus. C'est à vous de savoir comment l'adapter à vote code.
	int received, cpt = 0;
    while (cpt < length){
  
      received = recv(socket, buffer + cpt ,length - cpt, 0);

      if(received <= 0){
        return received;
      }
      
      cpt += received;
	
      (*nbBytesReceved)+=received;
      (*nbCallRecv)++;
    }
    return 1;
}


int main(int argc, char *argv[])
{
	 
  
  if (argc<2){
    printf("utilisation: %s numero_port\n", argv[0]);
    exit(1);
  }
  
  /*  Création de la socket d'écoute, nomage et mise en écoute.*/
 
  int ds = socket(PF_INET, SOCK_STREAM, 0);

  if (ds == -1){
    perror("Serveur : probleme creation socket");
    exit(1); 
  }
  printf("Serveur: creation de la socket : ok\n");

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(atoi(argv[1]));
  int lgAdr = sizeof(struct sockaddr_in);

  if(bind(ds, (struct sockaddr *) &server, lgAdr) < 0){
    perror("Serveur : erreur bind");
    close(ds);
    exit(1);
  }
  printf("Serveur: nommage : ok\n");
  
  int ecoute = listen(ds, 10);
  if (ecoute < 0){
    printf("Serveur : je suis sourd(e)\n");
    close (ds);
    exit (1);
  } 
  printf("Serveur: mise en écoute : ok\n");

  // Rappel un seul client est à traiter.
  printf("Serveur : j'attends la demande d'un client (accept) \n"); 
  
  struct sockaddr_in adCv;
  socklen_t lgCv = sizeof(struct sockaddr_in);
  fd_set toutesLesSockets, setTmp;
  FD_ZERO(&toutesLesSockets); //init toutes les sockets à 0
  FD_SET(ds, &toutesLesSockets);//on ajoutes ds à toutesLesSockets
  int indMax = ds;

  while(1){

    setTmp = toutesLesSockets;
    int nbRcv = select(indMax+1, &setTmp, NULL, NULL, NULL);

    if(FD_ISSET(ds, &setTmp)){

      FD_CLR(ds, &setTmp);
      printf("Serveur : j'attends la demande d'un client\n");
      int dsCv = accept(ds, (struct sockaddr *) &adCv, &lgCv);
      if (dsCv < 0){
        perror ( "Serveur, probleme accept :");
        close(ds);
        break;
      }
      printf("Serveur: le client %s:%d est connecté  \n", inet_ntoa(adCv.sin_addr),  ntohs(adCv.sin_port));

      FD_SET(dsCv, &toutesLesSockets);
      if(indMax < dsCv){
        indMax = dsCv;
      }
    }

    long int messagesRecus[2];
    unsigned int nbTotalOctetsRecus = 0;
    unsigned int nbAppelRecv = 0;

    while(1){ 
      
      int rcv = recvTCP (dsCv, (char*)(messagesRecus+1) , sizeof(long int), &nbTotalOctetsRecus, &nbAppelRecv);  

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

      printf("Serveur : j'ai reçu au total %d octets avec %d appels à recv \n", nbTotalOctetsRecus, nbAppelRecv);
  
    }

    // terminer proprement votre programme
    close (dsCv);
    printf("Serveur : fin du dialogue avec le client\n");
  }

  close (ds);
  printf("Serveur : je termine\n");
}









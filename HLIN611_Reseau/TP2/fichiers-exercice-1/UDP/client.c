#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include<string.h>

/* Rôle du client : 
- envoyer une demande de connexion à un serveur,

- envoyer au serveur la suite d'entiers (de type long int) de 1 à N,
   où chaque entier est un message à part entière (un appel à sendTCP
   par entier). N est passé en paramètre du programme client,

- afficher le nombre total d'appels de la fonction send et le nombre total d'octets effcetivement envoyés,

- terminer poprement
*/


int main(int argc, char *argv[]) {

  /* je passe en paramètre l'adresse de la socket d'écoute du serveur
     (IP et numéro de port) et le nombre N d'entiers à envoyerr. Je teste donc le passage de parametres */

  if (argc != 4){
    printf("utilisation : %s ip_serveur port_serveur N_nombre_entiers_e_envoyer\n", argv[0]);
    exit(0);
  }

  /* créer une socket, demader une connexion au serveur */   
  int ds = socket(PF_INET, SOCK_DGRAM, 0);
  if (ds == -1){
    printf("Client : pb creation socket\n");
    exit(1); 
  }
  printf("Client: creation de la socket : ok\n");
  
  struct sockaddr_in adrServ;
  adrServ.sin_addr.s_addr = inet_addr(argv[1]);
  adrServ.sin_family = AF_INET; 
  adrServ.sin_port = htons(atoi(argv[2]));
  socklen_t lgAdr = sizeof(struct sockaddr_in);

  long int message;
  unsigned int nbTotalOctetsEnvoyes = 0;
  unsigned int nbAppelSend = 0;

  for(int i = 1; i <= atoi(argv[3]); i++){
    message = i; // pour passer d'un int à long int (de 4 à 8 octets). Vous pouvez faire autrement.
    int snd = sendto(ds, (char *) &message, sizeof(long int), 0, (struct sockaddr *)&adrServ, lgAdr);

    /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
    if(snd<0){
      perror("Pb envoi message\n");
      close(ds);
      exit(1);
    }

    nbTotalOctetsEnvoyes += snd;
    nbAppelSend +=1;
    printf("Client : j'ai envoyé au total %d octets avec %d appels à send \n",nbTotalOctetsEnvoyes,  nbAppelSend) ;

  }
  /*Terminer proprement. */

  close (ds);
  printf("Client : je termine\n");
}

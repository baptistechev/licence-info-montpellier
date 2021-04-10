#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>


.....

int main(int argc, char *argv[])
{
	 
 // ajout d'un paramètre
  if (argc<3){
    printf("utilisation: %s numero_port taille_param_recv\n", argv[0]);
    exit(1);
  }
  
  ...

 
 
  long int messagesRecus[500]; // pour recevoir plusieurs éléments en bloc (jusqu'à 4000 octets)


    ... 
  // plus besoin de recevoir un premier message avant la boucle.
  // j'accepte toujours un seul client, je le traite et je termine.

  while(1){ 

    // je n'ai pas besoin de garder tous les messages, j'écrase les précédents.
    rcv = recvTCP (dsCv, (char*)messagesRecus, atoi(argv[2]), &nbTotalOctetsRecus, &nbAppelRecv);  

    ...

    printf("Serveur : j'ai reçu au total %d octets avec %d appels à recv \n", nbTotalOctetsRecus, nbAppelRecv);
 
  }
  
  ...

  printf("Serveur : je termine\n");
}









#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include<string.h>

#define MAX_BUFFER_SIZE 16000 // taille du buffer qui me permet de récupérer le contenu du fichier à recevoir bloc par bloc. Vous pouvez changer cette valeur.

int recvTCP(int socket, char *buffer, size_t length, unsigned int *nbBytesReceved, unsigned int * nbCallRecv){

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

  int dsCv = accept(ds, (struct sockaddr *) &adCv, &lgCv);
  if (dsCv < 0){
    perror ( "Serveur, probleme accept :");
    close(ds);
    exit (1);
  }

  printf("Serveur: le client %s:%d est connecté  \n", inet_ntoa(adCv.sin_addr),  ntohs(adCv.sin_port));
 
  /* Réception de messages, chaque message est un long int */
 
  char messagesRecus[MAX_BUFFER_SIZE];   
  unsigned int nbTotalOctetsRecus = 0;
  unsigned int nbAppelRecv = 0;
  
 /* boucle pour le traitement itératif des clients */
  while(1){

  
    // je doit recevoir des données me permettant d'obtenur le nom d'un fichier
    int rcv = recvTCP(dsCv, messagesRecus, sizeof(messagesRecus), &nbTotalOctetsRecus, &nbAppelRecv);
    if(rcv<0){
      perror("Pb envoi message\n");
      close(dsCv);
      close(ds);
      exit(1);
    }
    if(rcv == 0){
        printf("Socket fermee\n");
        close(dsCv);
        exit(2);
    }
    
    char* file_name = malloc(strlen(messagesRecus) +1 );
    file_name[strlen(messagesRecus)] = '\0';
    printf("Serveur, je vais recevoir le fichier %s\n", file_name);

  //   // je construis le chemin vers le fichier à créer.
  //   char* filepath = malloc(name_size + 16); // ./reception/+nom fichier
  //   filepath[0] = '\0';
  //   strcat(filepath, "./reception/");
  //   strcat(filepath, file_name);
  //   free(file_name);

  // // j'ouvre le fichier dans lequel je vais écrire
  //   FILE* file = fopen(filepath, "wb");
  //   if(file == NULL){  // servez vous de cet exemple pour le traitement des erreurs. 
  //     perror("Serveur : erreur ouverture fichier: \n");
  //     free(filepath);
  //     close (dsCv);
  //     continue; // passer au client suivant 
  //   }
    
  //   free(filepath); // je n'en ai plus besoin.

  //   //reception des données me permettant de recevoir correctement le contenu du fichier.
  //   int file_size;
  
  //   ...
      
  //   int contentReceived = 0; // Compte le nombre d'octets du fichier reçu

  //   // je reçois le contenu progressivement 
  //   while(contentReceived < file_size){
      
  //     char buffer[MAX_BUFFER_SIZE];
  //     rcv = recv(dsCv, buffer, MAX_BUFFER_SIZE, 0);  // /!\ ici appel
	// 					     // direct de recv
	// 					     // car recvTCP
	// 					     // n'est pas
	// 					     // adapté. Pourquoi ?

  //     ....
	
  //     // si pas d'erreurs, j'ai reçu rcv octets. Je dois les écire dans le fichier.
  //     size_t written = fwrite(buffer, sizeof(char), rcv, file);
  //     if(written < rcv){
	// perror("Serveur : Erreur a l'ecriture du fichier \n");
	// ....
	//   break; // je sors de la boucle d'écrture/réception.
  //     }

  //     contentReceived += ...;
  //   }

  //   // fermeture du fichier à la fin de son écriture ou si erreur s'est produite.
    
  //   fclose(file);
  //  printf("Serveur : fin du dialogue avec le client, nombre total d'octets recus : %d,  recus en %d appels a recv \n", ...);
    close (dsCv);
    //je passe au client suivant.
  }
  
  close (ds); // atteignable si on sort de la boucle infinie.
  printf("Serveur : je termine\n");
 }









#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include<string.h>

int sendTCP(int socket, const char * buffer, size_t length, unsigned int *nbBytesSent, unsigned int * nbCallSend){

  int sent, cpt =0;
  while (cpt < length){
    
    sent = send(socket, buffer + cpt ,length - cpt, 0);
    
    if (sent<=0) {
      return sent;
    }

    cpt+= sent;
    (*nbBytesSent)+=sent;
    (*nbCallSend)++;
  }
  return 1;
}

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

int main(int argc, char *argv[]) {

    /* je passe en paramètre l'adresse de la socket d'écoute du serveur
        (IP et numéro de port) et le nombre N d'entiers à envoyerr. Je teste donc le passage de parametres */

    if (argc != 3){
        printf("utilisation : %s ip_serveur port_serveur\n", argv[0]);
        exit(0);
    }

    /* créer une socket, demader une connexion au serveur */   
    int ds = socket(PF_INET, SOCK_STREAM, 0);
    if (ds == -1){
        printf("Client : pb creation socket\n");
        exit(1); 
    }
    printf("Client: creation de la socket : ok\n");
    
    struct sockaddr_in adrServ;
    adrServ.sin_addr.s_addr = inet_addr(argv[1]);
    adrServ.sin_family = AF_INET; 
    adrServ.sin_port = htons(atoi(argv[2]));
        
    int lgAdr = sizeof(struct sockaddr_in);

    int conn = connect(ds, (struct sockaddr *) &adrServ, lgAdr);
    if (conn <0){
        perror ("Client: pb au connect :");
        close (ds); 
        exit (1); 
    }
    printf("Client : demande de connexion reussie \n");

    char buffer[1000] = "baptiste";
    unsigned int nbTotalOctetsEnvoyes = 0;
    unsigned int nbAppelSend = 0;
    int taille = strlen(buffer);

    //Taille du login
    int snd = sendTCP(ds, (char*)&taille, sizeof(int), &nbTotalOctetsEnvoyes, &nbAppelSend);
    if(snd<0){
        perror("Pb envoi message\n");
        close(ds);
        exit(1);
    }
    if(snd == 0){
            printf("Socket fermee");
            close(ds);  
    }

    //Login
    snd = sendTCP(ds, buffer, taille, &nbTotalOctetsEnvoyes, &nbAppelSend);
    if(snd<0){
        perror("Pb envoi message\n");
        close(ds);
        exit(1);
    }
    if(snd == 0){
        printf("Socket fermee");
        close(ds);  
    }
    printf("Client : nombres d'appels %d \n", snd);

    int tailleMessageRecus;
    char messagesRecus[1000];
    unsigned int nbTotalOctetsRecus = 0;
    unsigned int nbAppelRecv = 0;

    int rcv = recvTCP (ds, (char*)tailleMessageRecus, sizeof(int), &nbTotalOctetsRecus, &nbAppelRecv);  
    /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
    if(rcv<0){
      perror("Pb envoi message\n");
      close(ds);
      close(ds);
      exit(1);
    }
    if(rcv == 0){
        printf("Socket fermee");
        close(ds);  
    }

    rcv = recvTCP (ds, (char*)messagesRecus, tailleMessageRecus, &nbTotalOctetsRecus, &nbAppelRecv);  
    /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
    if(rcv<0){
      perror("Pb envoi message\n");
      close(ds);
      close(ds);
      exit(1);
    }
    if(rcv == 0){
        printf("Socket fermee");
        close(ds);  
    }

    /*Terminer proprement. */
    close (ds);
    printf("Client : je termine\n");
}
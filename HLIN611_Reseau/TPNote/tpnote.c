#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include<string.h>


// ce programme est à compléter en fonction des instructions à
// recevoir depuis un processus serveur TCP distant. L'IP et le numéro de
// port du serveur sont fournis en début d'épreuve par les enseignants
// et sont à passer en paramètres de votre programme.

// Une instruction est sous forme de chaine de caractères (caractère
// de fin de chaine inclus) dont la taille (de type int) est à
// recevoir juste avant le texte de l'instruction. Donc, une
// instruction implique deux messages : un premier message qui est la
// taille (en nombre d'octets) du texte de l'instruction et un second
// message qui est le texte de l'instruction.

// Après execution d'une instruction, votre programme recoit un
// feedback avec l'instruction suivante. Là aussi, deux messages sont
// à recevoir : le premier qui est la taille (de type int) en nombre
// d'octets du second mesage qui est une chaine de caractères
// (caractère de fin inclus).

// Remarque 1 : un message de type chaine de caractères ne depassera jamais 6000 octets.
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

    if (argc != 4){
      printf("Utilisation : %s ip_serveur port_serveur param3 \n param3 est un entier dont la signification sera fournie par une instruction. En attendant cette instruction, passer n'importe quelle valeur\n", argv[0]);
      exit(1);
    }

    // première étape : se connecter au serveur et recevoir la première
    // instruction (lire commentaire plus haut). Bien évidement, il est
    // necessaire d'afficher le message reçu pour prendre connaissance
    // des instructions à suivre pour compléter votre programme.

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

    int tailleMessageRecus;
    char messagesRecus[6000];
    unsigned int nbTotalOctetsRecus = 0;
    unsigned int nbAppelRecv = 0;

    int rcv = recvTCP (ds, (char*) &tailleMessageRecus, sizeof(int), &nbTotalOctetsRecus, &nbAppelRecv);  
    if(rcv<0){
      perror("Pb reception message\n");
      close(ds);
      exit(1);
    }
    if(rcv == 0){
        printf("Socket fermee\n");
        close(ds);  
    }

    rcv = recvTCP (ds, (char*)messagesRecus, tailleMessageRecus, &nbTotalOctetsRecus, &nbAppelRecv);  
    if(rcv<0){
      perror("Pb envoi message\n");
      close(ds);
      exit(1);
    }
    if(rcv == 0){
        printf("Socket fermee\n");
        close(ds);  
    }
    printf("\n%s\n", messagesRecus);

    //On renvoit le message
    unsigned int nbTotalOctetsEnvoyes = 0;
    unsigned int nbAppelSend = 0;

    int snd = sendTCP(ds, messagesRecus, tailleMessageRecus, &nbTotalOctetsEnvoyes, &nbAppelSend);
    if(snd<0){
        perror("Pb envoi message\n");
        close(ds);
        exit(1);
    }
    if(snd == 0){
        printf("Socket fermee\n");
        close(ds);  
    }

    //Recevoir une nouvelle instruction
    rcv = recvTCP (ds, (char*) &tailleMessageRecus, sizeof(int), &nbTotalOctetsRecus, &nbAppelRecv);  
    if(rcv<0){
      perror("Pb reception message\n");
      close(ds);
      exit(1);
    }
    if(rcv == 0){
        printf("Socket fermee\n");
        close(ds);  
    }

    rcv = recvTCP (ds, (char*)messagesRecus, tailleMessageRecus, &nbTotalOctetsRecus, &nbAppelRecv);  
    if(rcv<0){
      perror("Pb reception message\n");
      close(ds);
      exit(1);
    }
    if(rcv == 0){
        printf("Socket fermee\n");
        close(ds);  
    }
    printf("\n%s\n", messagesRecus);

    /******************* Partie Serveur *************/

    int dsS = socket(PF_INET, SOCK_STREAM, 0);

    if (dsS == -1){
      perror("Serveur : probleme creation socket");
      exit(1); 
    }
    printf("Serveur: creation de la socket : ok\n");

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[3]));
    lgAdr = sizeof(struct sockaddr_in);

    if(bind(dsS, (struct sockaddr *) &server, lgAdr) < 0){
      perror("Serveur : erreur bind");
      close(dsS);
      exit(1);
    }
    printf("Serveur: nommage : ok\n");
    
    int ecoute = listen(dsS, 10);
    if (ecoute < 0){
      printf("Serveur : je suis sourd(e)\n");
      close (dsS);
      exit (1);
    } 
    printf("Serveur: mise en écoute : ok\n");

    //Envoit du numéro de port
    short port_num = atoi(argv[3]);
    snd = sendTCP(ds, (char*) &port_num, sizeof(short), &nbTotalOctetsEnvoyes, &nbAppelSend);
    if(snd<0){
        perror("Pb envoi message\n");
        close(ds);
        exit(1);
    }
    if(snd == 0){
        printf("Socket fermee\n");
        close(ds);  
    }
    //Fermeture du client
    close (ds);
    printf("Client : je termine\n");

    printf("Serveur : j'attends la demande d'un client (accept) \n"); 
    struct sockaddr_in adCv;
    socklen_t lgCv = sizeof(struct sockaddr_in);
    int dsCv, nbClient = 0;
    
    while(nbClient < 4){
        dsCv = accept(dsS, (struct sockaddr *) &adCv, &lgCv);
        if (dsCv < 0){
          perror ( "Serveur, probleme accept :");
          close(dsS);
          exit (1);
        }
        printf("Serveur: le client %s:%d est connecté  \n", inet_ntoa(adCv.sin_addr),  ntohs(adCv.sin_port));
        nbClient++;

        //Recevoir une instruction du client distant
        rcv = recvTCP (dsCv, (char*) &tailleMessageRecus, sizeof(int), &nbTotalOctetsRecus, &nbAppelRecv);  
        if(rcv<0){
          perror("Pb reception message\n");
          close(dsCv);
          close(dsS);
          exit(1);
        }
        if(rcv == 0){
            printf("Socket fermee\n");
            close(ds);  
        }

        rcv = recvTCP (dsCv, (char*)messagesRecus, tailleMessageRecus, &nbTotalOctetsRecus, &nbAppelRecv);  
        if(rcv<0){
          perror("Pb reception message\n");
          close(dsCv);
          close(dsS);
          exit(1);
        }
        if(rcv == 0){
            printf("Socket fermee\n");
            close(dsCv);  
        }
        printf("\n%s\n", messagesRecus);

        //------------Recevoir un message et le renvoyer-------

        rcv = recvTCP (dsCv, (char*) &tailleMessageRecus, sizeof(int), &nbTotalOctetsRecus, &nbAppelRecv);  
        if(rcv<0){
          perror("Pb reception message\n");
          close(dsCv);
          close(dsS);
          exit(1);
        }
        if(rcv == 0){
            printf("Socket fermee\n");
            close(ds);  
        }

        rcv = recvTCP (dsCv, (char*)messagesRecus, tailleMessageRecus, &nbTotalOctetsRecus, &nbAppelRecv);  
        if(rcv<0){
          perror("Pb reception message\n");
          close(dsCv);
          close(dsS);
          exit(1);
        }
        if(rcv == 0){
            printf("Socket fermee\n");
            close(dsCv);  
        }

        //On renvoit le message
        snd = sendTCP(dsCv, messagesRecus, tailleMessageRecus, &nbTotalOctetsEnvoyes, &nbAppelSend);
        if(snd<0){
            perror("Pb envoi message\n");
            close(dsCv);
            continue;
        }
        if(snd == 0){
            printf("Socket fermee\n");
            close(dsCv);  
        }

        //Recevoir une nouvelle instruction
        rcv = recvTCP (dsCv, (char*) &tailleMessageRecus, sizeof(int), &nbTotalOctetsRecus, &nbAppelRecv);  
        if(rcv<0){
          perror("Pb reception message\n");
          close(dsCv);
          close(dsS);
          exit(1);
        }
        if(rcv == 0){
            printf("Socket fermee\n");
            close(ds);  
        }

        rcv = recvTCP (dsCv, (char*)messagesRecus, tailleMessageRecus, &nbTotalOctetsRecus, &nbAppelRecv);  
        if(rcv<0){
          perror("Pb reception message\n");
          close(dsCv);
          close(dsS);
          exit(1);
        }
        if(rcv == 0){
            printf("Socket fermee\n");
            close(dsCv);  
        }
        printf("\n%s\n", messagesRecus);

        //Fermeture client distant
        close(dsCv);
        printf("Serveur : fin du dialogue avec le client\n");
    }

    //Fermeturte du serveur
    close (dsS);
    printf("Serveur : je termine\n");
}



#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include<string.h>

int main(int argc, char *argv[]) {

    if (argc != 3){
        printf("utilisation : %s ip_serveur port_serveur\n", argv[0]);
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

    char message[1000] = "baptiste";
    int snd = sendto(ds, message, strlen(message)+1, 0, (struct sockaddr *)&adrServ, lgAdr);
    /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
    if(snd<0){
        perror("Pb envoi message\n");
        close(ds);
        exit(1);
    }
    printf("Client : j'ai envoyé au total %d octets\n",snd);

    char messagesRecus[1000];
    struct sockaddr_in addrC ;
    socklen_t lgAddrC = sizeof(struct sockaddr_in) ;
    int rcv = recvfrom (ds, messagesRecus, sizeof(messagesRecus), 0, (struct sockaddr*)&addrC, &lgAddrC);
    /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation) */
    if(rcv<0){
        perror("Pb envoi message\n");
        close(ds);
        exit(1);
    }
    printf("Client: le serveur %s:%d m'a envoyé un message  \n", inet_ntoa(addrC.sin_addr), ntohs(addrC.sin_port));
    printf("Bonjour %s\n", messagesRecus);

    close (ds);
    printf("Client : je termine\n");
}
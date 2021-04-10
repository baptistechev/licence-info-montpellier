#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	 
    // je passe en paramètre un numero de port pour la socket du serveur
    
    if (argc<2){
        printf("utilisation: %s numero_port\n", argv[0]);
        exit(1);
    }
    
    /* Créer une socket */
    
    int ds = socket(PF_INET, SOCK_DGRAM, 0);
    
    if (ds == -1){
        perror("Serveur : probleme creation socket");
        exit(1); 
    }
    printf("Serveur: creation de la socket : ok\n");

    // nommage
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
    
    char buffer[1000];
    struct sockaddr_in addrC ;
    socklen_t lgAddrC = sizeof(struct sockaddr_in) ;
    int rcv = recvfrom (ds, buffer, sizeof(buffer), 0, (struct sockaddr*)&addrC, &lgAddrC);
    /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation) */
    if(rcv<0){
        perror("Pb envoi message\n");
        close(ds);
        exit(1);
    }
    printf("Serveur: le client %s:%d m'a envoyé un message  \n", inet_ntoa(addrC.sin_addr), ntohs(addrC.sin_port)); 
    
    int snd = sendto(ds, buffer, strlen(buffer)+1, 0, (struct sockaddr *)&addrC, lgAddrC);
    /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
    if(snd<0){
        perror("Pb envoi message\n");
        close(ds);
        exit(1);
    }
    printf("Client : j'ai envoyé au total %d octets\n",snd);

    /* je termine proprement */ 
    close(ds);
    printf("Serveur : je termine\n");
}
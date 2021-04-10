int sendTCP(int sock, void * msg, int sizeMsg, int *res){

    int snd, cpt = 0;
    while(cpt < sizeMsg){
        snd = send(sock, msg + cpt ,sizeMsg - cpt, 0);
        if(snd<=0){
            return snd;
        }
        *res+=1;
        cpt += snd;
    }
    return 1;

}

int recvTCP(int sock, void * msg, int sizeMsg, int *res){
    
    int rcv, cpt = 0;
    while(cpt < sizeMsg){
        rcv = recv(sock, msg + cpt ,sizeMsg - cpt, 0);
        if(rcv<=0){
            return rcv;
        }
        *res+=1;
        cpt += rcv;
    }
    return 1;

}
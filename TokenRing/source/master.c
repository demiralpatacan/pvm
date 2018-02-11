
#include "def.h"

int main() {
    int tids[NTASK];
    Token *token, tokenobj;
    token = &tokenobj;
    struct timeval tv;
    long clock_sec, clock_usec;
    
    pvm_spawn(SLAVENAME, NULL, PvmTaskDefault, "", NTASK, tids);
    token->number = 0;			//initial token number
    token->succ = tids[0];		//initial successor of master is process 0
    pvm_initsend(PvmDataDefault);
    pvm_pkint(tids, NTASK, 1);
    gettimeofday(&tv, NULL);
    pvm_pklong(&tv.tv_sec, 1, 1);
    pvm_pklong(&tv.tv_usec, 1, 1);
    pvm_mcast(tids, NTASK, MSG_MST);
    
    pvm_initsend(PvmDataDefault);
    pvm_pkint(&token->number, 1, 1);	//pack the token number
    gettimeofday(&tv, NULL);
    pvm_pklong(&tv.tv_sec,1,1);		//pack the token time information
    pvm_pklong(&tv.tv_usec,1,1);
    pvm_send(token->succ, MSG_SLV);	//send token to the successor
    
    pvm_recv(-1, MSG_SLV);		//receives token from the process 3
    pvm_upkint(&token->number, 1, 1);	//unpack the final version of token number
    pvm_upklong(&clock_sec,1,1);	//unpack token sent time
    pvm_upklong(&clock_usec,1,1);
    printf("Master: token %d has circulated the ring\n", token->number);
    printf("Master: Received message time: %ld:%ld\n",clock_sec, clock_usec);
    printf("Master: Local time: %ld:%ld\n", tv.tv_sec, tv.tv_usec);
    pvm_exit();
    return 0;
}

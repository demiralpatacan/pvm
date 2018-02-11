#include "def.h"

int main() {
    printf("\n");

    int i;
    Token *token, tokenobj;
    token= &tokenobj;
    token->succ = 0;			//successor is zero default
    int tid = pvm_mytid();
    int tids[NTASK];
    struct timeval tv;
    long l_sec, l_usec;

    pvm_recv(-1, MSG_MST);		//receive mcast
    pvm_upkint(tids, NTASK, 1);		//get all task ids
    pvm_upklong(&l_sec,1,1);		//get sent time info
    pvm_upklong(&l_usec,1,1);
    for (i = 0; i < NTASK-1; i++){
        if (tids[i] == tid) {
            token->succ = tids[i+1];	//assign its successor
            break;
        }
    }
    if(!token->succ)
	token->succ=pvm_parent();	//the successor of the last process will be master

    printf("Slave t%x, Successor TID: t%x\n", tid, token->succ);

    pvm_recv(-1, MSG_SLV);		//receive from slave
    pvm_upkint(&token->number, 1, 1);	//unpack token number
    pvm_upklong(&l_sec,1,1);		//unpack token time info
    pvm_upklong(&l_usec,1,1);
    printf("Slave t%x: Number %d is received\n", tid, token->number);
    printf("Slave: Received message time: %ld:%ld\n", l_sec, l_usec);
    token->number++;			//update token number
    pvm_initsend(PvmDataDefault);	//clear send buffer
    pvm_pkint(&token->number, 1, 1);	//pack the updated token number
    gettimeofday(&tv, NULL);
    pvm_pklong(&tv.tv_sec,1,1);		//pack the current time
    pvm_pklong(&tv.tv_usec,1,1);
    printf("Slave: Sending message at %ld:%ld\n", tv.tv_sec, tv.tv_usec);
    pvm_send(token->succ, MSG_SLV);	//send token to its successor
    pvm_exit();
    return 0;
}

#include "def.h"

int main() {
    int mytid;
    int nums[]={0,1,2,3,4,5,6,7,8};
    char *hosts[]={"node1","node2","node3","node4"};
    int sums[NTASK];
    int tids[NTASK], status[NTASK];
    char slave_name[NAMESIZE];
    int nproc, i, who;
    for(i=0; i<NTASK; i++){
        //assign the hostnames to the spawned tasks
        nproc = pvm_spawn(SLAVENAME, NULL, PvmTaskHost, hosts[i], 1, &tids[i]);
        if (nproc < 1) {
            perror("Could not start a task");
            return -1;
        }
    }
    mytid = pvm_mytid();
    printf("Master: my task ID is t%x\n", mytid);

    for (i = 0; i < NTASK; i++) {
        pvm_initsend(PvmDataDefault);
        pvm_pkint(&mytid, 1, 1);
        pvm_pkint(&i, 1, 1);            //pack the counter
        pvm_pkint(&nums[(i*2)+1],1,1);  //pack the left operand
        pvm_pkint(&nums[(i*2)+2],1,1);  //pack the right operand
        pvm_send(tids[i], MSG_MST);     //send the message
    }
 
    for (i = 0; i < NTASK; i++) {
        pvm_recv(tids[i], MSG_SLV);     //receive messages from slave
        pvm_upkint(&who, 1, 1);         
        pvm_upkstr(slave_name);
        pvm_upkint(&sums[i], 1, 1);
        printf("Master: process t%x is on host %s\n", who, slave_name);
        printf("Master: Sum is %d ---> node%d\n", sums[i], i+1);
    }
    pvm_exit();
    return 0;
}

// master.c

#include <stdio.h>
#include <pvm3.h>

#define SLAVENAME "slave"
#define NTASK 4  //total number of tasks
#define MSG_MST 1

static char *hosts[NTASK-1] = {"node2","node3","node4"};
static char message[]= "Hello World!";

int main() {
    int mytid, info, i;
    int tids[NTASK];
    int status[NTASK];

    info = pvm_addhosts(hosts, NTASK-1, status);  //add 3 more additional tasks
    if(info > 0 && info < NTASK-1)
        printf("Partial succes is indicated by spawning %d\n", info);
    else if(info < 1)
        printf("Total failure\n");
    else
        printf("%d Hosts added succesfuly\n", info);

    printf("Spawns new PVM tasks\n");
    pvm_spawn(SLAVENAME, NULL, PvmTaskDefault, "", NTASK, tids);
    
    mytid = pvm_mytid();
    printf("Master: My task id: t%x\n", mytid);

    for(i = 0; i< NTASK; i++){
        pvm_initsend(PvmDataDefault);  //clear send buffer
        pvm_pkint(&mytid, 1, 1);       //pack the integer data
        pvm_pkstr(message);            //pack the string data
        pvm_send(tids[i], MSG_MST);    //send data to a host
    }
    pvm_exit();
    return 0;
}

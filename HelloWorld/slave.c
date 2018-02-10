#include <stdio.h>
#include <stdlib.h>
#include <pvm3.h>

int main() {
    int size, tag, ptid, tid, messagesize;
    char *buffer = malloc(20);

    int k = pvm_recv(-1, -1);         //receive any message from any host
    pvm_upkint(&ptid, 1, 1);          //unpack parent tid
    pvm_upkstr(buffer);               //unpack string message
    printf("Slave: %s received from t%x\n", buffer, ptid);
    pvm_exit();
    return 0;
}

#include "def.h"

int main() {
    int i, j;
    struct timeval tv;
    long timestamp;

    pvm_initsend(PvmDataDefault);
    gettimeofday(&tv, NULL);
    timestamp = tv.tv_usec + 1;
    printf("Slave: Local time: %ld, Send time: %ld\n", tv.tv_usec, timestamp);
    pvm_pklong(&timestamp, 1, 1);	//Assume Only check for miliseconds
    pvm_send(pvm_parent(), MSG_SLV);
    pvm_exit();
    return 0;
}

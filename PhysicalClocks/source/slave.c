#include "def.h"

int main() {
    int i, j;
    struct timeval tv;

    pvm_initsend(PvmDataDefault);		//clear the send buffer
    gettimeofday(&tv, NULL);			//get local time
    pvm_pklong(&tv.tv_sec, 1, 1);		//pack local time info
    pvm_pklong(&tv.tv_usec, 1, 1);
    pvm_send(pvm_parent(), MSG_SLV);		//send the message to the master
    pvm_exit();
    return 0;
}

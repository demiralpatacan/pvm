#include "def.h"

int main() {
    int ptid, number, k;
    int mytid;
    int tids[NTASK];
    int left_operand, right_operand, sum;
    char *str = malloc(NAMESIZE);
    int size, tag, tid;
    int i = pvm_recv(-1, MSG_MST);      //receive message from the master node
    if (i < 0) {
        error("Unexpected error");
        return -1;
    }
    pvm_bufinfo(i, &size, &tag, &tid);
    printf("Slave: message size %d\n", size);
    pvm_upkint(&ptid, 1, 1);
    pvm_upkint(&number, 1, 1);
    pvm_upkint(&left_operand,1,1);
    pvm_upkint(&right_operand,1,1);
    printf("Slave: received from process t%x %d\n", ptid, number);
    printf("Slave: left operand is %d, right operand is %d\n", left_operand,
           right_operand);
    sum = left_operand + right_operand;
    mytid = pvm_mytid();
    pvm_initsend(PvmDataDefault);
    pvm_pkint(&mytid,1,1);
    gethostname(str, NAMESIZE);
    str[NAMESIZE-1] = 0;
    pvm_pkstr(str);
    pvm_pkint(&sum, 1, 1);
    pvm_send(ptid, MSG_SLV);
    
    pvm_exit();
    return 0;
}

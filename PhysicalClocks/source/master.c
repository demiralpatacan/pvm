#include "def.h"

int main() {
    int mytid;
    int tids[NTASK];
    char slave_name[NAMESIZE];
    int nproc, i;
    long clock_sec, clock_usec;
    struct timeval tv;

    mytid = pvm_mytid();
    nproc = pvm_spawn(SLAVENAME, NULL, PvmTaskDefault, "", NTASK, tids);

    if (nproc < NTASK) {
        perror("Could not start tasks");
	return -1;
    }

    printf("Master: my task ID is t%x\n", mytid);
    for (i = 0; i < nproc; i++) {
        pvm_recv(-1, MSG_SLV);			//receive message from slave
        gettimeofday(&tv, NULL);         	//get local time
        pvm_upklong(&clock_sec, 1, 1);		//unpack time from slave
        pvm_upklong(&clock_usec, 1, 1);
        printf("Master: message sent at %ld:%ld,\n", clock_sec, clock_usec);
        printf("            received at %ld:%ld\n", tv.tv_sec, tv.tv_usec);
        if(tv.tv_usec < clock_usec)
            printf("WARNING! Message received before sent\n");
    }
    pvm_exit();
    return 0;
}

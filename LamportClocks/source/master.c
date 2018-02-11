#include "def.h"

int main() {
    int mytid;
    int tids[NTASK];
    char slave_name[NAMESIZE];
    int nproc, i;
    long clock_usec, logical_clock, incrementer;
    struct timeval tv; 
 
    incrementer = 1.0;                  //value can be anything greater than zero
    mytid = pvm_mytid();
    nproc = pvm_spawn(SLAVENAME, NULL, PvmTaskDefault, "", NTASK, tids);

    if (nproc < NTASK) {
        perror("Could not start tasks");
	return -1;
    }

    for (i = 0; i < nproc; i++) {
        pvm_recv(-1, MSG_SLV);			//receive message from slave
        gettimeofday(&tv, NULL);		//get local time;
        logical_clock = tv.tv_usec;		//set logical clock;
        pvm_upklong(&clock_usec, 1, 1);		//unpack slave's local clock
        printf("Master: received slave clock: %ld\n", clock_usec);
        if (logical_clock <= clock_usec)	//compare clocks
            logical_clock = clock_usec + incrementer;

        printf("Master: message sent at %d, received at %d\n",
            clock_usec, logical_clock);
    }
    pvm_exit();
    return 0;
}

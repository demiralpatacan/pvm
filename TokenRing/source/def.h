#include <stdio.h>
#include <stdlib.h>
#include <pvm3.h>
#include <sys/time.h>

#define SLAVENAME "slave"
#define NTASK 4
#define MSG_MST 1
#define MSG_SLV 2

struct Token;

typedef struct Token{
	int number;
	int succ;
} Token;

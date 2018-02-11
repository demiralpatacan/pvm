# 5. Token Ring

In this example, we see a method to achieve mutual exclusion in distributed systems. We create a logical ring in which each process is assigned a position in a ring. The ring positions are allocated by task ids. The only important thing is that each process knows who is next in line after itself, which is called its successor.

First, the ring is initialized and the master node gives process zero a token. In this example, token is an integer number which is defined in struct Token. The token circulates around the ring. It passes from master to slaves and finaly ends in master again.

master--->node1--->node2--->node3--->node4--->master

To run the program, write in console:

`pvm`

pvm> `add node2 node3 node4`

pvm>`spawn -> master`

![alt text](https://github.com/demiralpatacan/pvm/blob/master/TokenRing/img1.png "img1")

The output gives us information of either the token or the message sending time. We see that each process increments the token number by 1 and finally the master node receives and prints the token.

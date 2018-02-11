# 5. Lamport's Logical Clocks

This example shows a solution for the pyhsical clock problem by using logical clocks.

Synchronizing clocks across processes is very hard problem in distributed system. We want to achieve this because we want to order events becase events are occured in different processes in distributed systems. Instead of doing clock synchronization, we directly assign timestamps to events. If event A happens before another event B, then timestamp(A) < timestamp(B).

Lamport defined a logical relation called *Happen-Before* among pairs of events. According to the rules of that relationship,
1. On the same process,	if timestamp(B) < timestamp(B), then **A ---> B** (event A happens before event B).
2. If A is event of message *m* sent by process P(1) and B is event of message *n* received by process P(2),
then **A ---> B**.
3. This relationship is transitive, meaning if A ---> B and B ---> C, then **A ---> C**.

To run the program, in the console:

`pvm`

pvm> `add node2 node3 node4`

pvm>`spawn -> master`

![alt text](https://github.com/demiralpatacan/pvm/blob/master/LamportClocks/img1.png "img1")

The output shows that no message is received before it has sent. We can solve event ordering problem with logical clocks. However, Lamport's Clocks have limitations.

1. Nothing can be said about the actual time of events. If A ---> B, it does not mean in reality that A actually happened before B in terms of real time.
2. If A ----> C, and B ----> C, then we cannot say anything about the relation between A and B.
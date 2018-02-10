# 2. Summation

In this example, master node sends two integers to each host. Hosts receive the message, get the integers, do summation and send back the sum to the master node. Then, master node prints the sums for each nodes.

Assume that it is mandatory to send the integers in order:

1, 2 ----------> node1

3, 4 ----------> node2

5, 6 ----------> node3

7, 8 ----------> node4


To run the program, run the followings in the console:

`pvm`

pvm> `conf`

pvm> `add node2 node3 node4`

pvm> `conf`


Instead of writing `pvm_addhosts()` in the master source file, now we add the hosts manually on the PVM console by typing `add node2 node3 node4`. After adding the hosts, the output should be like this.

![alt text](https://github.com/demiralpatacan/pvm/blob/master/Summation/img1.png "img1")


pvm>`spawn -> master`

Let's spawn the master, run the program and analyse it.

![alt text](https://github.com/demiralpatacan/pvm/blob/master/Summation/img2.png "img2")

The hosts receive message from master. Message includes the task id of the master node and the integer numbers. The hosts calculate the sum of the integers received and send back the sum to the master node. After master node receives the message from hosts, it prints the sum and related node.

This example is basicly we see that the messaging is biidirectional. The slave nodes send back a message. Moreover, here the master node does not do the computation, but it makes the slaves do the computation. Its only job is sending/receiving messages and printing.
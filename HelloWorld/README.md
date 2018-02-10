# 1. HelloWorld

In this example, master node adds 3 more hosts (nodes) and assign tasks to them, including itself. That means we have 4 machines which also means 4 nodes. Master host spawns 4 tasks and sends message to each of them. The exercise is simply to make slave hosts print "Hello World!" message received from the master host.

To run the program, run the followings in the console:

`pvm`

pvm> `conf`

![alt text](https://github.com/demiralpatacan/pvm/blob/master/HelloWorld/img1.png "img1")

There is only master node. Let's spawn the master node and let the master spawn the other nodes and run the program.

pvm>`spawn -> master`

To analyse the code, let's run `conf` again.

![alt text](https://github.com/demiralpatacan/pvm/blob/master/HelloWorld/img2.png "img2")

There are four nodes (the virtual machines) with different task ids. The output of the program shows that master node spawns 3 additional nodes, spawns 4 tasks on the nodes and sends message to those nodes. Then, first slave node is master's itself. It receives the string message and prints it. The other nodes do the same. 

This example is basicly we see that the messaging is unidirectional. The slave nodes do not send message back to the master node.
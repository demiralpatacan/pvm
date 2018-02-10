# pvm
Distributed processing practices using C and the PVM software.

This directory includes parallel virtual machines programming examples by using the software PVM (http://www.netlib.org/pvm3/).

User needs to have virtual machines (in the practices, there are 4) sharing the local network on the user computer.

To run the code before executing command `pvm` , user needs to comple the source files and distribute the nodes among the machines.

<b>```gcc master.c -o master -lpvm3

   gcc slave.c -o slave -lpvm3

   cp-nodes master slave ```</b>

# 1. HelloWorld

In this example, master node adds 3 more hosts (nodes) and assign tasks to them, including itself. That means we have 4 machines which also means 4 nodes. Master host spawns 4 tasks and sends message to each of them. The exercise is simply to make slave hosts print "Hello World!" message received from the master host.
# pvm
Distributed processing practices using C and the PVM software.

This directory includes parallel virtual machines programming examples by using the software PVM (http://www.netlib.org/pvm3/).

User needs to have virtual machines (in the practices, there are 4) sharing the local network on the user computer.

To run the code before executing command `pvm` , user needs to comple the source files and distribute the nodes among the machines.

`gcc master.c -o master -lpvm3`

`gcc slave.c -o slave -lpvm3`

`cp-nodes master slave`

## 1. Hello World
## 2. Summation
## 3. Physical Clocks
## 4. Lamport's Logical Clocks
## 5. Token Ring
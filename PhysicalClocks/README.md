# 3. Physical Clocks

This example shows that what kind of problems local clocks may cause in distributed systems.

Every computer has a physical clock which also is called timer. The timer counts the oscillations in a crystal at a particular frequency. Count is stored in counter register. Clock can be programmed to generate interrupts at regular intervals. Counter can be scaled to get time of day.

Assume that slaves send message to the master node and the message contains time information. Master receives messages, then compares the time info of message sent to master's local time info when message received.


To run the program, in the console:

`pvm`

pvm> `add node2 node3 node4`

pvm>`spawn -> master`

![alt text](https://github.com/demiralpatacan/pvm/blob/master/PhysicalClocks/img1.png "img1")

In the fist output, there seems no problem. However, when you run `spawn -> master` one or two more times, you will see those warnings. That means, the master receives message before the message has sent by slave. This is a problem. Some systems really need accurate absolute times. So there need to synchonize the clocks.
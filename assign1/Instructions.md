# Priority Queue of Processes

First, you should get the starter code for the assignment from the GitHub repository [csusm-cs/cs433_assign_starter (github.com)](https://github.com/csusm-cs/cs433_assign_starter) (Links to an external site.). The starter code of assignment 1 is under the directory `assign1`. Your program should be based on the starter code.

## Goal

This assignment aims to help you review C/C++ data structures and familiarize you with Unix/Linux programming environment that is used in later assignments. If you are new to Linux programming and Makefile, read the introduction to [Unix programming tools](https://csusm.instructure.com/courses/2598/files/762648/download?wrap=1)

## Starter Code

- **pcb.h:** It defines a PCB class. Add your names to the file header and complete the implementation of a few simple member functions. Remove TODOs from the comments after you are done.

- **pcbtable.h and .cpp:** It defines a PCBTable class, which can be just an array of PCB pointers, e.g. vector<PCB\*>. Complete the implementation in pcbtable.h and .cpp file. Make sure to release dynamically allocated memory to avoid memory leaks.

- **readyqueue.h and .cpp:** It defines the ReadyQueue class, which is a priority queue of PCBs in the ready state. See below for more details about its member functions. Complete the implementation of this class by choosing an appropriate data structure. Don't use STL classes for its implementation.

- **test1.cpp and test2.cpp:** Driver programs to test the data structures. Read below for more details of the test, but you don't need to make changes to those files.

## Overview

In this assignment, you will implement some commonly used data structures in operating systems, including:

**PCB:** Process control block (PCB) is a data structure representing a process in the system. For this assignment, just think of PCB as a simple class with three attributes: an integer ID, an integer priority, and a state (i.e., NEW, READY, RUNNING, WAITING, or TERMINATED). Not used in this assignment, a real PCB may also have other attributes (discussed more in later chapters, not needed for this assignment), such as Program Counter, CPU Registers, scheduling information (e.g., priority), and Memory-management information, and I/O status information, etc.

**PCB Table:** An array(list) of PCB elements. It contains all processes currently in the system.

**ReadyQueue:** Ready queue is a queue of PCBs that are in the READY state, which are to be scheduled to run on the CPU. It is a priority queue such that the process (PCB) with the highest priority can be selected next. It should support at least the following member functions:

- **_addPCB:_** add a PCB into the ready
- **_removePCB:_** remove and return the PCB with the highest priority from the queue
- **_size:_** return the number of elements in the queue
- **_displayAll:_** Display the IDs and priorities of processes in the

Those classes have been defined in the starter code. You need to complete their implementations, i.e. all the "TODO"s in the code. Delete "TODO" from your code after completing them. You may add additional member functions to facilitate the implementations, but don't change the definitions of those given functions.

You have the freedom of choosing the data structure, for example, linked-list, array, binary tree, or heap, used for implementing the **ReadyQueue.** However, in this assignment, you shouldn't directly use any existing data structure from STL to implement the ReadyQueue, for example, "priority_queue" or "vector" etc. The choice of the data structure for ReadyQueue implementation is critical for the performance of your program. In the report, you should discuss your choice of data structure, the expected time complexity of your implementation, and how the timing results match your expectations.

The implementation should satisfy the following assumptions:

- Assume the PCB priority has positive integer values ranging from 1 to 50, with the higher value representing the higher priority, i.e., priority = 1 represents the lowest priority and 50 the highest.
- When a PCB is first created, it is in the NEW state.
- When a PCB is added to the ReadyQueue, its state should be changed to READY.
- When a PCB is removed from the ReadyQueue, its state is changed to RUNNING.

## Testing

You will test the correctness and performance of your implementations. Two test programs `test1.cpp` and `test2.cpp` and a Makefile are provided to build the executables test1 and test2 in a Linux environment. To build the executables `test1` and `test2`, type `make` at the command line, and then run each test.

    $ make
    $ ./test1
    $ ./test2

1. The first program tests the correctness of the ReadyQueue implementation by adding and removing some PCBs. In this test, it assumes a PCB of ID i has an initial priority = i. For example, process 1 is assumed to have a priority of 1. Test1 performs the following sequence of operations:

   1. create an empty ReadyQueu q1.
   2. add processes 15, 6, 23, 39, and 8 to q1. Display the content of q1.
   3. remove the process with the highest priority and display q1.
   4. add processes 47, 1, 37, and 5 into q1, and display.
   5. remove the process with the highest priority from and display q1.
   6. add processes 43, 17, 32, 12, and 19 to and display q1.
   7. One by one remove the process with the highest priority from q1 and display it after each removal.

The output of your test1 should match what is in the "test1_out.txt" file.

2. The second test evaluates the performance of your implementation. It creates a ReadyQueue q2, and 200 PCBs with random priority between 1 and 50 in a PCBTable. It then adds half of the PCBs randomly into q2. It then repeats the following steps 1,000,000 times and measures the total running time.

- With equal probability (50% chance), randomly decide either to remove a process from or insert a process into the ReadyQueue.

The final content of q2 of your test2 should match what is in the "test2_out.txt" file. Your choice of the data structure for implementing the ReadyQueue class would affect its performance. In the report, you should present and discuss your timing results and the data structure you used.

## Extra Credits

Your test2 should run correctly in under 1 second. You will get 5-point extra credits if test2 runs under 0.1 seconds by using an efficient data structure and implementation.

## Submission

You need to submit the following required source code files and the report file (in PDF format) for Assignment 1 on the [GradeScope](https://www.gradescope.com/courses/408289) (Links to an external site.).

- pcb.h
- pcbtable.h
- pcbtable.cpp
- readyqueue.h
- readyqueue.cpp

Each group submits only one copy of the code and report. Please clearly list the group members in the code comments and the report.

Your student account has been added to the Gradescope. Please let me know if you need help accessing it. The GradeScope uses an autograder to check your code and gives immediate feedback. In order to receive credits for programming assignments, your code must be able to compile and run. You can make changes and resubmit as many times as you want before the due date.

You can use the course entry code:BBBP64 and campus email to register if your account hasn't been added to the gradescope.

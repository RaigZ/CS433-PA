/**
 * Assignment 1: priority queue of processes
 * @file readyqueue.h
 * @author Ragir Zebari and Edgar Del Valle (TODO: your name)
 * @brief ReadyQueue is a queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 * @version 0.1
 */
// You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
//  Remember to add sufficient comments to your code
#pragma once

#include "pcb.h"

/**
 * @brief A queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 */

int const MAX = 100000;
class ReadyQueue
{
private:
    // choose a data structure for the ReadyQueue. No STL class is allowed.
    PCB *Q[MAX] {};
    int count;

public:
    /**
     * @brief Construct a new ReadyQueue object
     *
     */
    ReadyQueue();

    /**
     * @brief Destructor
     */
    ~ReadyQueue() {}

    // You may add additional member functions, but don't change the definitions of the following four member functions.

    /**
     * @brief Add a PCB representing a process into the ready queue.
     *
     * @param pcbPtr: the pointer to the PCB to be added
     */
    void addPCB(PCB *pcbPtr);

    /**
     * @brief Remove and return the PCB with the highest priority from the queue
     *
     * @return PCB*: the pointer to the PCB with the highest priority
     */
    PCB *removePCB();

    /**
     * @brief Returns the number of elements in the queue.
     *
     * @return int: the number of PCBs in the queue
     */
    int size();

    /**
     * @brief Display the PCBs in the queue.
     */
    void displayAll();

    // Utility functions

    /**
     * @brief Helper function to swap two PCBs in the heap.
     * @param a: index of one PCB in the heap
     * @param b: index of another PCB in the heap
     */
    void swap(int, int);
    /**
     * @brief Helper function to get the index of the current element's parrent in the heap.
     * @param idx: index of the PCB in the heap
     * @return the index of the parent PCB
     */
    int getParent(int);
    /**
     * @brief Helper function to get the index of the left child of the current index in the heap.
     * @param idx: index of the PCB in the heap
     * @return the index of the left child PCB
     */
    int leftChild(int);
    /**
     * @brief Helper function to get the index of the right child of the current index in the heap.
     * @param idx: index of the PCB in the heap
     * @return the index of the right child PCB
     */
    int rightChild(int);
    /**
     * @brief Helper function to get bubble up the just-added PCB onto the currect position in the heap.
     */
    void heapifyUp();
    /**
     * @brief Helper function to get trickle down the PCB that was swapped after removing a PCB in a heap.
     */
    void heapifyDown();
};
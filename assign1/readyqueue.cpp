#include <iostream>
#include "readyqueue.h"
#include "pcb.h"

using namespace std;

// You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
//  Remember to add sufficient comments to your code

/**
 * @brief Constructor for the ReadyQueue class.
 */
ReadyQueue::ReadyQueue()
{
    // TODO: add your code here
    count = 0;
}

/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr)
{
    //  When adding a PCB to the queue, you must change its state to READY.
    // First check if we have reached the max amount of processes.
    if (count >= MAX)
    {
        cout << "Cannot add to full queue" << endl;
    }
    else
    {
        // Change the state to ready before adding into the heap.
        pcbPtr->setState(ProcState::READY);
        Q[count] = pcbPtr;
        count++;
        heapifyUp();
    }
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB *ReadyQueue::removePCB()
{
    // TODO: add your code here
    //  When removing a PCB from the queue, you must change its state to RUNNING.
    PCB *pcb = Q[0];
    pcb->setState(ProcState::RUNNING);
    Q[0] = Q[count - 1];
    count--;
    heapifyDown();
    return pcb;
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size()
{
    return count;
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll()
{
    for (int i = 0; i < count; i++)
    {
        PCB *currentPCB = Q[i];
        currentPCB->display();
    }
}

/**
 * @brief Helper function to swap two PCBs in the heap.
 * @param a: index of one PCB in the heap
 * @param b: index of another PCB in the heap
 */
void ReadyQueue::swap(int a, int b)
{
    // Set the PCB at index a in a temporary variable
    PCB *temp = Q[a];
    // Set the PCB at index a to be equal to the PCB in index b
    Q[a] = Q[b];
    // Set the PCB at index b to be equal to the PCB stored in the temporary variable
    Q[b] = temp;
}
/**
 * @brief Helper function to get the index of the current element's parrent in the heap.
 * @param idx: index of the PCB in the heap
 * @return the index of the parent PCB
 */
int ReadyQueue::getParent(int idx)
{
    // Property of heap
    return (idx - 1) / 2;
}
/**
 * @brief Helper function to get the index of the left child of the current index in the heap.
 * @param idx: index of the PCB in the heap
 * @return the index of the left child PCB
 */
int ReadyQueue::leftChild(int idx)
{
    // Property of heap
    return 2 * idx + 1;
}
/**
 * @brief Helper function to get the index of the right child of the current index in the heap.
 * @param idx: index of the PCB in the heap
 * @return the index of the right child PCB
 */
int ReadyQueue::rightChild(int idx)
{
    // Property of heap
    return 2 * idx + 2;
}
/**
 * @brief Helper function to get bubble up the just-added PCB onto the currect position in the heap.
 */
void ReadyQueue::heapifyUp()
{
    // Start at the end of the array
    int idx = count - 1;
    // While the index of the parent of the current index is in bounds and priority of the parent is less than the priority of the current index
    while (getParent(idx) >= 0 && Q[getParent(idx)]->priority < Q[idx]->priority)
    {
        // Swap the element in the current index with it's parent
        swap(idx, getParent(idx));
        // Move the current index to the parent to compare that with it's next parent
        idx = getParent(idx);
    }
}
/**
 * @brief Helper function to get trickle down the PCB that was swapped after removing a PCB in a heap.
 */
void ReadyQueue::heapifyDown()
{
    // Start current index at 0
    int idx = 0;

    // While a left child exists (No need to check for right child since a right child cannot exist if there is no left child)
    while (leftChild(idx) < count)
    {
        // Starting variable for the index of the PCB with the higher priority
        int larger = leftChild(idx);
        // First check if right child is in bounds and then compare the priority of the right child PCB and the left child PCB
        if (rightChild(idx) < count && Q[rightChild(idx)]->priority > Q[leftChild(idx)]->priority)
        {
            // If the right child's priority is higher than the left child's priority, update the larger variable to the right child index
            larger = rightChild(idx);
        }

        // if the priority of the current index is larger than the larger of the two children, we can break out of the loop since PCB's are
        // in the correct position
        if (Q[idx]->priority > Q[larger]->priority)
        {
            break;
        }
        // If the PCB at the current index has a lower priority than that larger of the two children, swap the parent with the child
        else
        {
            swap(idx, larger);
        }
        // Move current index to compare to the parent to continue comparing
        idx = larger;
    }
}

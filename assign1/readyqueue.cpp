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
    // TODO: add your code here
    //  When adding a PCB to the queue, you must change its state to READY.
    if (count >= MAX)
    {
        cout << "Cannot add to full queue" << endl;
    }
    else
    {
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
    // TODO: add your code here
    return count;
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll()
{
    // TODO: add your code here

    for (int i = 0; i < count; i++)
    {
        PCB *currentPCB = Q[i];
        currentPCB->display();
    }
}

void ReadyQueue::swap(int a, int b)
{
    PCB *temp = Q[a];
    Q[a] = Q[b];
    Q[b] = temp;
}

int ReadyQueue::getParent(int idx)
{
    return (idx - 1) / 2;
}

int ReadyQueue::leftChild(int idx)
{
    return 2 * idx + 1;
}

int ReadyQueue::rightChild(int idx)
{
    return 2 * idx + 2;
}

void ReadyQueue::heapifyUp()
{
    int idx = count - 1;

    while (getParent(idx) >= 0 && Q[getParent(idx)]->priority < Q[idx]->priority)
    {
        swap(idx, getParent(idx));
        idx = getParent(idx);
    }
}

void ReadyQueue::heapifyDown()
{
    cout << "Display Processes in ReadyQueue: " << endl;
    int idx = 0;

    while (leftChild(idx) < count)
    {
        int larger = leftChild(idx);
        if (rightChild(idx) < count && Q[rightChild(idx)]->priority > Q[leftChild(idx)]->priority)
        {
            larger = rightChild(idx);
        }

        if (Q[idx]->priority > Q[larger]->priority)
        {
            break;
        }
        else
        {
            swap(idx, larger);
        }
        idx = larger;
    }
}

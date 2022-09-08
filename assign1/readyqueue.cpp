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
        count += 1;
        trickleup();
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
    Q[0]->setState(ProcState::RUNNING);
    reheapify();
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
        cout << "ID: " << currentPCB->getID() << ", Priority: " << currentPCB->getPriority() << ", State: " << endl; // << currentPCB->getState() << endl;
    }
}

void ReadyQueue::swap(PCB *a, PCB *b)
{
    PCB *temp = a;
    a = b;
    b = temp;
}

void ReadyQueue::reheapify()
{
    int X = 0;
    Q[X] = Q[count - 1];
    count--;

    while (X < count - 1)
    {
        int largerChild = getLargerchild(X);

        if (largerChild == -1 || Q[largerChild] > Q[X])
            break;

        X = largerChild;
        swap(Q[X], Q[getParent(X)]);
    }
}

int ReadyQueue::getLargerchild(int i)
{
    int LC = 2 * i + 1;
    int RC = 2 * i + 2;

    if (LC > count - 1)
        return -1;
    if (RC > count - 1)
        return -1;

    if (Q[LC]->priority > Q[RC]->priority)
        return LC;
    else
        return RC;
}

void ReadyQueue::trickleup()
{
    int X = count - 1;

    while (X > 0)
    {
        if (Q[getParent(X)]->priority < Q[X]->priority)
        {
            swap(Q[getParent(X)], Q[X]);
        }
        X = getParent(X);
    }
}

int ReadyQueue::getParent(int i)
{
    if (even(i))
        return (i - 1) / 2;
    else
        return (i - 1) / 2 - 1;
}

bool ReadyQueue::even(int num)
{
    return (num % 2 == 0);
}
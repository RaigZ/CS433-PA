/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author Ragir Zebari and Edgar Del Valle (TODO: your name)
 * @brief This is the implementation file for the PCBTable class.
 * //You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
 * // Remember to add sufficient comments to your code
 */

#include "pcbtable.h"
#include "pcb.h"
#include <vector>

/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size)
{
    // TODO: add your code here
    this->size = size;
    this->table.reserve(size);
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable()
{
    // TODO: add your code here
    table.clear();
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
PCB *PCBTable::getPCB(unsigned int idx)
{
    return this->table.at(idx);
}

/**
 * @brief Add a PCB to the PCBTable.
 *
 * @param pcb: the PCB to add
 * @param idx: the index to add the PCB at
 */
void PCBTable::addPCB(PCB *pcb, unsigned int idx)
{
    this->table.push_back(pcb);
}

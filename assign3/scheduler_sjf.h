/**
* Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.h
 * @author Edgar Del Valle and Ragir Zebari
 * @brief This Scheduler class implements the SJF scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#ifndef ASSIGN3_SCHEDULER_SJF_H
#define ASSIGN3_SCHEDULER_SJF_H

#include "scheduler.h"
#include <queue>

struct pcb_stat {
  string id;
  unsigned int tat;
  unsigned int wt;
};

class SchedulerSJF : public Scheduler {
private:
    // TODO: add necessary member variables here for your implementation
    vector<pcb_stat> stats;
    queue<PCB> process_queue;
    unsigned int current_time = 0;

    int sum_waiting_time = 0;
    int sum_turn_around_time = 0;

public:
    /**
     * @brief Construct a new SchedulerSJF object
     */
    SchedulerSJF();
    /**
     * @brief Destroy the SchedulerSJF object
     */
    ~SchedulerSJF() override;
    /**
     * @brief This function is called once before the simulation starts.
     *        It is used to initialize the scheduler.
     * @param process_list The list of processes in the simulation.
     */
    void init(std::vector<PCB>& process_list) override;
    /**
     * @brief This function is called once after the simulation ends.
     *        It is used to print out the results of the simulation.
     */
    void print_results() override;

    /**
     * @brief This function simulates the scheduling of processes in the ready queue.
     *        It stops when all processes are finished.
     */
    void simulate() override;
};
#endif //ASSIGN3_SCHEDULER_SJF_H

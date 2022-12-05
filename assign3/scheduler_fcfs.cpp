/**
 * Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.cpp
 * @author Edgar Del Valle and Ragir Zebari
 * @brief This Scheduler class implements the FCSF scheduling algorithm.
 * @version 0.1
 */
// You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
//  Remember to add sufficient and clear comments to your code

#include "scheduler_fcfs.h"

SchedulerFCFS::SchedulerFCFS()
{
}

SchedulerFCFS::~SchedulerFCFS()
{
}

/**
 * @brief Initialize FCFS Scheduler
 * @param process_list: The list of processes that have been read into memory.
 */
void SchedulerFCFS::init(std::vector<PCB> &process_list)
{
  // Push every process into a queue
  for (int i = 0; i < process_list.size(); i++)
  {
    process_queue.push(process_list[i]);
  }
}

/**
 * @brief Print the turn around time and waiting time along with the averages.
 */
void SchedulerFCFS::print_results()
{
  for (int i = 0; i < stats.size(); i++)
  {
    std::cout << stats[i].id << " turn-around time = " << stats[i].tat << ", waiting time = " << stats[i].wt << std::endl;
    sum_waiting_time += stats[i].wt;
    sum_turn_around_time += stats[i].tat;
  }
  std::cout << "Average turn-around time = " << sum_turn_around_time * 1.0 / stats.size() << ", Average waiting time = " << sum_waiting_time * 1.0 / stats.size() << std::endl;
}

/**
 * @brief Simulate each process being scheduled.
 */
void SchedulerFCFS::simulate()
{
  // While there are still processes to go through.
  while (!process_queue.empty())
  {
    // Initialize a pcb_stat struct to keep track of the process waiting time and turn around time.
    struct pcb_stat pcb = {process_queue.front().name, current_time, current_time + process_queue.front().burst_time};

    stats.push_back(pcb);
    current_time += process_queue.front().burst_time;
    process_queue.pop();
  }
}

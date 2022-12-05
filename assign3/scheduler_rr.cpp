/**
 * Assignment 3: CPU Scheduler
 * @file scheduler_rr.h
 * @author Edgar Del Valle and Ragir Zebari
 * @brief This Scheduler class implements the RoundRobin (RR) scheduling algorithm.
 * @version 0.1
 */
// You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
//  Remember to add sufficient and clear comments to your code
//

#include "scheduler_rr.h"

SchedulerRR::SchedulerRR(int time_quantum)
{
  this->time_quantum = time_quantum;
}

SchedulerRR::~SchedulerRR()
{
}

/**
 * @brief Initialize Priority Scheduler
 * @param process_list: The list of processes that have been read into memory.
 */
void SchedulerRR::init(std::vector<PCB> &process_list)
{
  for (int i = 0; i < process_list.size(); i++)
  {
    pcbs.push_back(process_list[i]);
  }
}

/**
 * @brief Print the turn around time and waiting time along with the averages.
 */
void SchedulerRR::print_results()
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
void SchedulerRR::simulate()
{
  vector<int> remaining_bt; // Vector to keep track of the remaining burst time of each process
  // Create a copy of the processes' burst time
  for (int i = 0; i < pcbs.size(); i++)
  {
    remaining_bt.push_back(pcbs[i].burst_time);
  }
  while (1)
  {
    bool done = true;
    // Iterate through each process
    for (int i = 0; i < pcbs.size(); i++)
    {
      // If a process has any remaining burst time
      if (remaining_bt[i] > 0)
      {
        // There are still some processes in the queue
        done = false;

        // Check if the remaining burst time is grater than the time quantum
        if (remaining_bt[i] > time_quantum)
        {
          // Increment the current time only by the time quantum
          current_time += time_quantum;
          remaining_bt[i] -= time_quantum;
        }
        else
        {
          // Process can run through completion, increment time by it's burst time and record waiting time/turn around time
          struct pcb_stat pcb;
          current_time += remaining_bt[i];
          remaining_bt[i] = 0;
          pcb.id = pcbs[i].name;
          pcb.tat = current_time;
          pcb.wt = pcb.tat - pcbs[i].burst_time;
          stats.push_back(pcb);
        }
      }
    }
    // Break out of while loop once all PCBs have been processed
    if (done == true)
      break;
  }
}

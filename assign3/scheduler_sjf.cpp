/**
 * Assignment 3: CPU Scheduler
 * @file scheduler_sjf.cpp
 * @author Edgar Del Valle and Ragir Zebari
 * @brief This Scheduler class implements the SJF scheduling algorithm.
 * @version 0.1
 */
// You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
//  Remember to add sufficient and clear comments to your code

#include "scheduler_sjf.h"

// TODO: add implementation of SchedulerFCFS constructor, destrcutor and
// member functions init, print_results, and simulate here

SchedulerSJF::SchedulerSJF()
{
}

SchedulerSJF::~SchedulerSJF()
{
}

void SchedulerSJF::init(std::vector<PCB> &process_list)
{
  for (int i = 1; i < process_list.size(); i++)
  {
    PCB key = process_list[i];
    int j = i - 1;

    while (key.burst_time < process_list[j].burst_time && j >= 0)
    {
      process_list[j + 1] = process_list[j];
      j -= 1;
    }
    process_list[j + 1] = key;
  }

  for (int i = 0; i < process_list.size(); i++)
  {
    process_queue.push(process_list[i]);
  }
}

void SchedulerSJF::print_results()
{
  for (int i = 0; i < stats.size(); i++)
  {
    std::cout << stats[i].id << " turn-around time = " << stats[i].tat << ", waiting time = " << stats[i].wt << std::endl;
    sum_waiting_time += stats[i].wt;
    sum_turn_around_time += stats[i].tat;
  }
  std::cout << "Average turn-around time = " << sum_turn_around_time * 1.0 / stats.size() << ", Average waiting time = " << sum_waiting_time * 1.0 / stats.size() << std::endl;
}

void SchedulerSJF::simulate()
{
  while (!process_queue.empty())
  {
    struct pcb_stat pcb = {process_queue.front().name, current_time, current_time + process_queue.front().burst_time};

    stats.push_back(pcb);
    current_time += process_queue.front().burst_time;
    process_queue.pop();
  }
}
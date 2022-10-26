/**
* Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.cpp
 * @author Edgar Del Valle and Ragir Zebari
 * @brief This Scheduler class implements the FCSF scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "scheduler_fcfs.h"

// TODO: add implementation of SchedulerFCFS constructor, destrcutor and 
// member functions init, print_results, and simulate here

void SchedulerFCFS::init(std::vector<PCB>& process_list){
  for(int i = 0; i < process_list.size(); i++){
    process_queue.push(process_list[i]);
  }
}

void SchedulerFCFS::print_results() {
  for(int i = 0; i < stats.size(); i++){
    std::cout << stats[i].id << " turn-around time = " << stats[i].tat << ", waiting time = " << stats[i].wt << endl;
  }
}

void SchedulerFCFS::simulate(){
  for(int i = 0; i < process_queue.size(); i++){
    pcb_stat pcb;
    pcb.id = process_queue.front().name;
    pcb.wt = current_time;
    pcb.tat = process_queue.front().burst_time;

    stats.push_back(pcb);
    current_time += process_queue.front().burst_time;
    process_queue.pop();
  }
}

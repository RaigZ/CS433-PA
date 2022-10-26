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


SchedulerFCFS::SchedulerFCFS(){
  
}

SchedulerFCFS::~SchedulerFCFS(){

}


void SchedulerFCFS::init(std::vector<PCB>& process_list){
  for(int i = 0; i < process_list.size(); i++){
    process_queue.push(process_list[i]);
  }

}

void SchedulerFCFS::print_results() {
  for(int i = 0; i < stats.size(); i++){
    std::cout << stats[i].id << " turn-around time = " << stats[i].tat << ", waiting time = " << stats[i].wt << std::endl;
    sum_waiting_time += stats[i].wt;
    sum_turn_around_time += stats[i].tat;
  }
  average_turn_around_time = sum_turn_around_time * 1.0 / stats.size();
  average_waiting_time = sum_waiting_time * 1.0 / stats.size();
  std::cout << "Average turn-around time = " << average_turn_around_time << ", Average waiting time = " << average_waiting_time << std::endl;
}

void SchedulerFCFS::simulate(){
  while(!process_queue.empty()){
    pcb_stat pcb;
    pcb.id = process_queue.front().name;
    pcb.wt = current_time;
    pcb.tat = current_time + process_queue.front().burst_time;

    stats.push_back(pcb);
    current_time += process_queue.front().burst_time;
    process_queue.pop();
  }
}

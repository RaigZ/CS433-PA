/**
* Assignment 4: Producer Consumer Problem
 * @file buffer.cpp
 * @author Edgar Del Valle and Ragir Zebari
 * @brief Implementation file for the buffer class
 * @version 0.1
 */

// Remember to add sufficient and clear comments to your code
#include "buffer.h"
#include <iostream>

Buffer::Buffer(int size): items(){
  this->size = size;
  this->front = -1;
  this->rear = -1;
  this->counter = 0;
}

Buffer::~Buffer(){
}

/**
 * @brief Insert an item into the buffer
 * @param item the item to insert
 * @return true if successful
 * @return false if not successful
 */
bool Buffer::insert_item(buffer_item item){
  // If the buffer is full the operation is not successfull, if the buffer has space then the operation is successfull
  if(this->is_full()){
    return false;
  } else {
    if(this->front == -1){
      this->front = 0;
    }
    rear = (rear + 1) % BUFFER_SIZE;
    this->items[rear] = item;
    this->counter++;
    return true;
  }
}

/**
 * @brief Remove an item from the buffer
 * @param item the item to remove
 * @return true if successful
 * @return false if not successful
 */
bool Buffer::remove_item(buffer_item *item){
  // If the buffer is empty, the operation is not successfull, if the buffer has items remaining then the operation is successfull
  if(this->is_empty()){
    return false;
  } else {
    *item = this->items[this->front];
    if(this->front == this->rear){
      this->front = -1;
      this->rear = -1;
    } else {
      front = (front + 1) % BUFFER_SIZE;
    }
    this->counter--;
    return true;
  }
}

/**
 * @brief Get the size of the buffer
 * @return the size of the buffer
 */
int Buffer::get_size(){
  return BUFFER_SIZE;
}

/**
 * @brief Get the number of items in the buffer
 * @return the number of items in the buffer
 */
int Buffer::get_count(){
  return this->counter;
}

/**
 * @brief Chceck if the buffer is empty
 * @return true if the buffer is empty, else false
 */
bool Buffer::is_empty(){
  if(this->front == -1){
    return true;
  } else {
    return false;
  }
}
/**
 * @brief Check if the buffer is full
 * @return true if the buffer is full, else false
 */
bool Buffer::is_full(){
  if(this->front == 0 && this->rear == BUFFER_SIZE - 1){
    return true;
  }
  if(this->front == this->rear + 1){
    return true;
  }
  return false;
}

/**
 * @brief Print the buffer
 */
void Buffer::print_buffer(){
  std::cout << "[";
  
  if(!this->is_empty()){
    if (this->front <= this->rear){
      for(int i = this->front; i < this->rear; i++){
        std::cout << this->items[i] << ", ";
      }
      std::cout << this->items[this->rear];
    } else {
      for(int i = this->front; i < BUFFER_SIZE; i++){
        std::cout << this->items[i] << ", ";
      }
      for(int i = 0; i < this->rear; i++){
        std::cout << this->items[i] << ", ";
      }
      std::cout << this->items[this->rear];
    }
  }

  std::cout << "]" << std::endl;
}
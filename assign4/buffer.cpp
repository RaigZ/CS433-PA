/**
* Assignment 4: Producer Consumer Problem
 * @file buffer.cpp
 * @author Edgar Del Valle and Ragir Zebari
 * @brief Implementation file for the buffer class
 * @version 0.1
 */

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include "buffer.h"

// TODO: Add your implementation of the buffer class here
Buffer::Buffer(int size = 5){
  this->size = size;
}


/**
 * @brief Insert an item into the buffer
 * @param item the item to insert
 * @return true if successful
 * @return false if not successful
 */
bool Buffer::insert_item(buffer_item item){
  if(this->is_full()){
    return false;
  } else {
    this->items.push(item);
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
  if (this->is_empty()){
    return false;
  } else {
    this->items.pop();
    return true;
  }
}

/**
 * @brief Get the size of the buffer
 * @return the size of the buffer
 */
int Buffer::get_size(){
  return this->size;
}

/**
 * @brief Get the number of items in the buffer
 * @return the number of items in the buffer
 */
int Buffer::get_count(){
  return this->items.size();
}

/**
 * @brief Chceck if the buffer is empty
 * @return true if the buffer is empty, else false
 */
bool Buffer::is_empty(){
  return this->items.empty();
}
/**
 * @brief Check if the buffer is full
 * @return true if the buffer is full, else false
 */
bool Buffer::is_full(){
  return this->items.size() == this->size;
}

/**
 * @brief Print the buffer
 */
void Buffer::print_buffer(){

}
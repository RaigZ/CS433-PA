/**
* Assignment 4: Producer Consumer Problem
 * @file main.cpp
 * @author Edgar Del Valle and Ragir Zebari
 * @brief The main program for the producer consumer problem.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include <iostream>
#include "buffer.h"
#include <unistd.h>
#include <pthread.h>

using namespace std;

// global buffer object
Buffer buffer;

// Producer thread function
// TODO: Add your implementation of the producer thread here
void *producer(void *param) {
    // Each producer insert its own ID into the buffer
    // For example, thread 1 will insert 1, thread 2 will insert 2, and so on.
    buffer_item item = *((int *) param);

    while (true) {
        /* sleep for a random period of time */
        usleep(rand()%1000000);
        // TODO: Add synchronization code here
        pthread_mutex_lock(&buffer.mutex);
        if (buffer.insert_item(item)) {
            cout << "Producer " << item << ": Inserted item " << item << endl;
            buffer.print_buffer();
        } else {
            cout << "Producer error condition"  << endl;    // shouldn't come here
        }
        pthread_mutex_unlock(&buffer.mutex);
    }
}

// Consumer thread function
// TODO: Add your implementation of the consumer thread here
void *consumer(void *param) {
    buffer_item item;

    while (true) {
        /* sleep for a random period of time */
        usleep(rand() % 1000000);
        // TODO: Add synchronization code here
        pthread_mutex_lock(&buffer.mutex);        
        if (buffer.remove_item(&item)) {
            cout << "Consumer " << item << ": Removed item " << item << endl;
            buffer.print_buffer();
        } else {
            cout << "Consumer error condition" << endl;    // shouldn't come here
        }
        pthread_mutex_unlock(&buffer.mutex);
    }
}

int main(int argc, char *argv[]) {
    /* TODO: 1. Get command line arguments argv[1],argv[2],argv[3] */
    if(argc != 4){
        // std::cout << "Incorrect number of arguments." << std::end;
        return -1;
    }

    pthread_t producer_thread;
    pthread_t consumer_thread;

    int mtsleep = stoi(argv[1]);
    int num_of_producers = stoi(argv[2]);
    int num_of_consumers = stoi(argv[3]);
    /* TODO: 2. Initialize buffer and synchronization primitives */
    pthread_mutex_init(&buffer.mutex, NULL);
    pthread_attr_init(&buffer.attr);
    /* TODO: 3. Create producer thread(s).
     * You should pass an unique int ID to each producer thread, starting from 1 to number of threads */
    int prod_counter = 0;
    for (int i = 0; i < num_of_producers; i++){
        pthread_create(&producer_thread, &buffer.attr, producer, (void*) (size_t) prod_counter);
    }
    /* TODO: 4. Create consumer thread(s) */
    int con_counter = 0;
    for (int i = 0; i < num_of_consumers; i++){
        pthread_create(&consumer_thread, &buffer.attr, producer, (void*) (size_t) con_counter);
    }
    /* TODO: 5. Main thread sleep */
    // pthread_join(producer_thread, NULL);
    // pthread_join(consumer_thread, NULL);
    usleep(1000 * mtsleep);
    /* TODO: 6. Exit */
    std::cout << "Exit program." << std::endl;
}

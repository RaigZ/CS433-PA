/**
* Assignment 4: Producer Consumer Problem
 * @file main.cpp
 * @author Edgar Del Valle and Ragir Zebari
 * @brief The main program for the producer consumer problem.
 * @version 0.1
 */

// Remember to add sufficient and clear comments to your code
#include <iostream>
#include "buffer.h"
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

// global buffer object
Buffer buffer;
sem_t full; //Full sempahore
sem_t empty_sem; //Empty sempahore

// Producer thread function

void *producer(void *param) {
    // Each producer insert its own ID into the buffer
    // For example, thread 1 will insert 1, thread 2 will insert 2, and so on.
    buffer_item item = *((int *) param);
    while (true) {
        /* sleep for a random period of time */
        usleep(rand()%1000000);

        sem_wait(&empty_sem);
        //Acquire lock
        pthread_mutex_lock(&buffer.mutex);
        if (buffer.insert_item(item)) {
            cout << "Producer " << item << ": Inserted item " << item << endl;
            buffer.print_buffer();
        } else {
            cout << "Producer error condition"  << endl;    // shouldn't come here
        }
        // Release lock
        pthread_mutex_unlock(&buffer.mutex);
        sem_post(&full);
    }
}

// Consumer thread function
void *consumer(void *param) {
    buffer_item item;
    while (true) {
        /* sleep for a random period of time */
        usleep(rand() % 1000000);

        sem_wait(&full);
        // Aquire lock
        pthread_mutex_lock(&buffer.mutex);        
        if (buffer.remove_item(&item)) {
            cout << "Consumer " << item << ": Removed item " << item << endl;
            buffer.print_buffer();
        } else {
            cout << "Consumer error condition" << endl;    // shouldn't come here
        }
        // Release Lock
        pthread_mutex_unlock(&buffer.mutex);
        sem_post(&empty_sem);
    }
}

int main(int argc, char *argv[]) {
    if(argc != 4){
        return -1;
    }

    // Assign the arguments passed
    int mtsleep = atoi(argv[1]);
    int num_of_producers = atoi(argv[2]);
    int num_of_consumers = atoi(argv[3]);

    // Create the producer thread and consumer thread ids
    pthread_t producer_thread;
    pthread_t consumer_thread;

    // Initialize Mutex Lock
    pthread_mutex_init(&buffer.mutex, NULL);

    sem_init(&full, 0, 0);
    sem_init(&empty_sem, 0, buffer.get_size());
    
    int i;
    int j;
    // Create the appropriate amount of threads
    for (i = 1; i <= num_of_producers; i++){
        pthread_create(&producer_thread, NULL, producer, (void*) new int(i));
    }

    for (j = 1; j <= num_of_consumers; j++){
        pthread_create(&consumer_thread, NULL, consumer, (void*) (size_t) &j);
    }

    usleep(1000000 * mtsleep);

    std::cout << "Exit program." << std::endl;
    exit(0);
}

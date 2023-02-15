#ifndef QUEUE_TWO_SEDES_H
#define QUEUE_TWO_SEDES_H

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 256 // The size of the queue

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

typedef int queue_type; // The type of the elements of the queue

typedef struct queue   
{
    unsigned char tail    = 0;          // The index of the tail in the queue
    unsigned char head    = 0;          // The index of the head in the queue
    size_t size           = QUEUE_SIZE; // The size of the queue
    size_t num_in_queu    = 0;          // The number of the 
    queue_type* queue_ptr = nullptr;    // The pointer to the array with elements of the queue
}queue;

const queue_type POISON = 0xDED; // The poison value for elements of the queue

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief 
 * 
 */
void queue_print(queue* queue_str);

/**
 * @brief 
 * 
 * @param queue_str 
 */
void queue_ctor(queue* queue_str);

/**
 * @brief 
 * 
 */
void queue_dtor(queue* queue_str);

/**
 * @brief 
 * 
 * @param queue_str 
 */
void logic(queue* queue_str);

/**
 * @brief 
 * 
 * @param queue_str 
 * @return size_t 
 */
size_t check_tail_head(queue* queue_str);

/**
 * @brief 
 * 
 * @param queue_str 
 * @return queue_type 
 */
queue_type pop_tail_queue(queue* queue_str);

/**
 * @brief 
 * 
 * @param queue_str 
 * @return queue_type 
 */
queue_type pop_head_queue(queue* queue_str);

/**
 * @brief 
 * 
 * @param queue_str 
 * @param val 
 */
void push_head_queue(queue* queue_str, queue_type val);

/**
 * @brief 
 * 
 * @param queue_str 
 * @param val 
 */
void push_tail_queue(queue* queue_str, queue_type val);


#endif
#ifndef QUEUE_TWO_SEDES_H
#define QUEUE_TWO_SEDES_H

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 256 // The size of the queue
#define FUNC_NAME __func__ // used in order to get the name of the function which called the dump
#define FUNC_LINE __LINE__ // used in order to get the line from which the dump was called
#define FUNC_FILE __FILE__ // used in order to get the file name from which the dump was called

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

enum error_code
{
    OK               = 0,
    ERR_QUEUE_NULPTR = 1,
    ERR_INV_TAIL     = 2,
    ERR_INV_HEAD     = 3,
    ERR_NUM_IN_Q     = 4
};

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

typedef int queue_type; // The type of the elements of the queue

typedef struct queue   
{
    unsigned char tail    = 0;          // The index of the tail in the queue
    unsigned char head    = 0;          // The index of the head in the queue
    size_t size           = QUEUE_SIZE; // The size of the queue
    size_t num_in_queu    = 0;          // The number of the 
    queue_type* queue_ptr = nullptr;    // The pointer to the array with elements of the queue
    size_t error_code     = OK;
}queue;

const queue_type POISON = 0xDED; // The poison value for elements of the queue

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Function that prints the struct of the queue and all its elements       
 * 
 * @param queue is the main struct of the program, which contains all information about queue
 */
void queue_print(queue* queue_str);

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Function that creates and initializes the main struct of the program
 * 
 * @param queue is the main struct of the program, which contains all information about queue 
 */
void queue_ctor(queue* queue_str);


/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Function that deletes all data about the main struct of the program, moreover it deletes all elements of the queue
 * 
 * @param queue is the main struct of the program, which contains all information about queue
 */
void queue_dtor(queue* queue_str);

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Function that controls function calls according to the input
 * 
 * @param queue_str is the main struct of the program, which contains all information about queue
 */
void logic(queue* queue_str);

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Function which is used in order to prevent overflow of the queue
 * 
 * @param queue_str is the main struct of the program, which contains all information about queue
 * @return size_t is the logic flag, which controls overflow of the queue
 */
size_t check_tail_head(queue* queue_str);

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Function that deletes the element of the queue from the tail of the queue 
 * 
 * @param queue_str is the main struct of the program, which contains all information about queue
 * @return queue_type is the element deleted from the head of the queue
 */
queue_type pop_tail_queue(queue* queue_str);

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Function that deletes the element of the queue from the head of the queue 
 * 
 * @param queue_str is the main struct of the program, which contains all information about queue
 * @return queue_type is the element deleted from the head of the queue
 */
queue_type pop_head_queue(queue* queue_str);

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Function that pushes the element to the head of the queue
 * 
 * @param queue_str is the main struct of the program, which contains all information about queue
 * @param val is the element's value, that will be added to the tail of the queue
 */
void push_head_queue(queue* queue_str, queue_type val);

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Function that pushes the element to the tail of the queue
 * 
 * @param queue_str is the main struct of the program, which contains all information about queue
 * @param val is the element's value, that will be added to the tail of the queue
 */
void push_tail_queue(queue* queue_str, queue_type val);

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Converts enum error code of the struct to the string
 * 
 * @param error_code is the error code of the struct
 * @return const char* the name of the error code in enum, which is converted to the string
 */
const char* enum_to_string(size_t error_code);

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Checks for errors, calls dump and dtor if needed
 * 
 * @param queue_str is the main struct of the program, which contains all information about queue
 */
void check_errors(queue* queue_str, const char* FNC_NAME, size_t FNC_LINE, const char* FILE_NAME);

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Prints to the dump file all data about queue struct
 * 
 * @param queue_str is the main struct of the program, which contains all information about queue
 */
void queue_dump(queue* queue_str, const char* FNC_NAME, size_t FNC_LINE, const char* FILE_NAME);

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
#endif
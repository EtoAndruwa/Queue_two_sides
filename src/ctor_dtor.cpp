#include "queue_two_sides.h"

void queue_ctor(queue* queue_str)
{
    queue_str->head = 120;
    queue_str->tail = 121;
    queue_str->num_in_queu = 0;
    queue_str->queue_ptr = (queue_type*)calloc(queue_str->size, sizeof(queue_type));

    for(size_t i = 0; i < queue_str->size; i++)
    {
        queue_str->queue_ptr[i] = POISON;
    }
}

void queue_dtor(queue* queue_str)
{
    for(size_t i = 0; i < queue_str->size; i++)
    {
        queue_str->queue_ptr[i] = POISON;
    }

    queue_str->head = POISON;
    queue_str->tail = POISON;
    queue_str->size = POISON;
    queue_str->num_in_queu = POISON;
    free(queue_str->queue_ptr);
    queue_str->queue_ptr = nullptr;
}
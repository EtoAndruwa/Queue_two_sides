#include "queue_two_sides.h"

void queue_print(queue* queue_str)
{  
    printf("\nqueue_str->head: %d\n", queue_str->head);
    printf("queue_str->tail: %d\n", queue_str->tail);
    printf("queue_str->size: %ld\n", queue_str->size);
    printf("queue_str->num_in_queu: %ld\n\n", queue_str->num_in_queu);

    for(size_t i = 0; i < queue_str->size; i++)
    {
        printf("queue[%ld] = %d ", i, queue_str->queue_ptr[i]);
        if((i == queue_str->tail) && (i == queue_str->head))
        {
            printf("<--------HEAD & TAIL");
        }
        else if(i == queue_str->head)
        {
            printf("<--------HEAD");
        }
        else if(i == queue_str->tail)
        {
            printf("<--------TAIL");
        }
        printf("\n");
    }
}
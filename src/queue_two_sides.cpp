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

void push_tail_queue(queue* queue_str, queue_type val)
{
    if(check_tail_head(queue_str))
    {   
        queue_str->queue_ptr[queue_str->tail] = val;
        queue_str->tail++;
        queue_str->num_in_queu++;
    }
    else
    {
        printf("queue if full! pls pop\n");
    }
}

void push_head_queue(queue* queue_str, queue_type val)
{
    if(check_tail_head(queue_str))
    {   
        queue_str->queue_ptr[queue_str->head] = val;
        queue_str->head--;
        queue_str->num_in_queu++;
    }
    else
    {
        printf("queue if full! pls pop\n");
    }
}

queue_type pop_tail_queue(queue* queue_str)
{
    if(queue_str->num_in_queu != 0)
    {   
        queue_str->tail--;
        queue_type val_pop = queue_str->queue_ptr[queue_str->tail];
        queue_str->queue_ptr[queue_str->tail] = POISON;
        queue_str->num_in_queu--;
        printf("popped value: %d\n", val_pop);
        return val_pop;
    }
    else
    {
        printf("queue is empty! pls push\n");
    }
}

queue_type pop_head_queue(queue* queue_str)
{
    if(queue_str->num_in_queu != 0)
    {   
        queue_str->head++;
        queue_type val_pop = queue_str->queue_ptr[queue_str->head];
        queue_str->queue_ptr[queue_str->head] = POISON;
        queue_str->num_in_queu--;
        printf("popped value: %d\n", val_pop);
        return val_pop;
    }
    else
    {
        printf("queue is empty! pls push\n");
    }
}

size_t check_tail_head(queue* queue_str)
{
    if(((queue_str->tail == (queue_str->head - 1)) || ((queue_str->tail - 1) == queue_str->head)) && (queue_str->num_in_queu != 0))
    {
        return 0; // Queue is full
    }
    else
    {   
        return 1; // Queue is not full
    }
}

void logic(queue* queue_str)
{
    size_t command_id = 0;
    queue_type val = 0;
    while(command_id != 6)
    {
        printf("1 - push to head, 2 - pop from head, 3 - push to tail, 4 - pop from tail, 5 - print, 6 - exit\n");
        scanf("%ld", &command_id);
        switch (command_id)
        {
        case 1:
            if(scanf(" %d", &val))
            {
                push_head_queue(queue_str, val);
            }
            else
            {   
                val = 0;
                printf("invalid argument\n");
            }
            break;
        case 2:
            pop_head_queue(queue_str);
            break;
        case 3:
            if(scanf(" %d", &val))
            {
                push_tail_queue(queue_str, val);
            }
            else
            {   
                val = 0;
                printf("invalid argument\n");
            }
            break;
        case 4:
            pop_tail_queue(queue_str);
            break;
        case 5:
            queue_print(queue_str);
            break;
        case 6:
            break;
        default:
            printf("invalid command id, try again\n");
            break;
        } 
    }
}
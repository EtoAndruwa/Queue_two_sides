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

void queue_dump(queue* queue_str, const char* FNC_NAME, size_t FNC_LINE, const char* FILE_NAME)
{
    FILE* dump_file = fopen("dump_queue.txt", "w");
    
    fprintf(dump_file, "----------------------STRUCT_DATA----------------------\n");
    fprintf(dump_file, "Error code: %ld (%s)\n", queue_str->error_code, enum_to_string(queue_str->error_code));
    fprintf(dump_file, "Tail: %d\n", queue_str->tail);
    fprintf(dump_file, "Head: %d\n", queue_str->head);
    fprintf(dump_file, "Queue size: %ld\n", queue_str->size);
    fprintf(dump_file, "Total number of elements: %ld\n", queue_str->num_in_queu);
    fprintf(dump_file, "Address of the queue: %p\n", queue_str->queue_ptr);
    fprintf(dump_file, "----------------------STRUCT_DATA----------------------\n");

    fprintf(dump_file, "\n----------------------DUMP_DATA----------------------\n");
    fprintf(dump_file, "Called from file: %s\n", FILE_NAME);
    fprintf(dump_file, "Called function name: %s\n", FNC_NAME);
    fprintf(dump_file, "Called from line: %ld\n", FNC_LINE);    
    fprintf(dump_file, "Date when was called: %s\n", __DATE__);
    fprintf(dump_file, "Time when was called: %s\n", __TIME__);
    fprintf(dump_file, "----------------------DUMP_DATA----------------------\n\n");

    if(queue_str->queue_ptr != nullptr)
    {   
        for(size_t i = 0; i < queue_str->size; i++)
        {
            fprintf(dump_file, "queue[%ld] = %d ", i, queue_str->queue_ptr[i]);
            if((i == queue_str->tail) && (i == queue_str->head))
            {
                fprintf(dump_file, "<--------HEAD & TAIL");
            }
            else if(i == queue_str->head)
            {
                fprintf(dump_file, "<--------HEAD");
            }
            else if(i == queue_str->tail)
            {
                fprintf(dump_file, "<--------TAIL");
            }
            fprintf(dump_file, "\n");
        }
    }

    fclose(dump_file);
}
#include "queue_two_sides.h"

void check_errors(queue* queue_str, const char* FNC_NAME, size_t FNC_LINE, const char* FILE_NAME)
{
    if(queue_str->queue_ptr == nullptr)
    {
        queue_str->error_code = ERR_QUEUE_NULPTR;
        queue_dump(queue_str, FNC_NAME, FNC_LINE, FILE_NAME);
        queue_dtor(queue_str);
    }
    else if(queue_str->head < 0 || queue_str->head > 255)
    {
        queue_str->error_code = ERR_INV_HEAD;
        queue_dump(queue_str, FNC_NAME, FNC_LINE, FILE_NAME);
        queue_dtor(queue_str);
    }
    else if(queue_str->tail < 0 || queue_str->tail > 255)
    {
        queue_str->error_code = ERR_INV_TAIL;
        queue_dump(queue_str, FNC_NAME, FNC_LINE, FILE_NAME);
        queue_dtor(queue_str);
    }
    else if(queue_str->num_in_queu < 0 || queue_str->num_in_queu > 256)
    {
        queue_str->error_code = ERR_INV_TAIL;
        queue_dump(queue_str, FNC_NAME, FNC_LINE, FILE_NAME);
        queue_dtor(queue_str);
    }
    else
    {
        queue_dump(queue_str, FNC_NAME, FNC_LINE, FILE_NAME);
    }
}

size_t check_tail_head(queue* queue_str)
{
    check_errors(queue_str, FUNC_NAME, FUNC_LINE, FUNC_FILE);

    if(((queue_str->tail == (queue_str->head - 1)) || ((queue_str->tail - 1) == queue_str->head)) && (queue_str->num_in_queu != 0))
    {
        return 0; // Queue is full
    }
    else
    {   
        return 1; // Queue is not full
    }
}
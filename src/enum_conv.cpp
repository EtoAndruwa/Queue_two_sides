#include "queue_two_sides.h"

const char* enum_to_string(size_t error_code)
{
    switch(error_code)
    {
        case OK:
            return "OK";
        case ERR_QUEUE_NULPTR:
            return "ERR_QUEUE_NULPTR";
        case ERR_INV_HEAD:
            return "ERR_INV_HEAD";
        case ERR_INV_TAIL:
            return "ERR_INV_HEAD";
        case ERR_NUM_IN_Q:
            return "ERR_NUM_IN_Q";
        default:
            return "NEW_ERR_CODE";
    }
}
#include "queue_two_sides.h"

int main()
{  
    queue queue_str = {};
    queue_ctor(&queue_str);
    logic(&queue_str);
    queue_dtor(&queue_str);
    return 0;
}
#include <stdlib.h>
#include "common.h"
#include "memory.h"

int MEMORY_COUNT = 0;

void *reallocate(void *pointer, size_t old_size, size_t new_size)
{

    if (new_size == 0)
    {
#ifdef DEBUG_TRACE_EXECUTION
        if (old_size != 0)
        {
            MEMORY_COUNT--;
        }
#endif

        free(pointer);
        return NULL;
    }

#ifdef DEBUG_TRACE_EXECUTION
    if (old_size != 0)
    {
        MEMORY_COUNT--;
    }

    MEMORY_COUNT++;
#endif

    void *result = realloc(pointer, new_size);

    if (result == NULL)
        exit(1);

    return result;
}

#include <stdlib.h>
#include "../include/memory.h"
#include "stack.h"

void init_stack(Stack *stack)
{
    stack->count = 0;
    stack->capacity = 0;
    stack->top = NULL;
    stack->values = NULL;
}

void push_stack(Stack *stack, Value value)
{
    if (stack->capacity < stack->count + 1)
    {
        int old_capacity = stack->capacity;
        stack->capacity = old_capacity == 0 ? 256 : GROW_CAPACITY(old_capacity);
        stack->values = GROW_ARRAY(Value, stack->values, old_capacity, stack->capacity);
    }

    stack->values[stack->count] = value;
    stack->top = stack->values + (++stack->count);
}

Value pop_stack(Stack *stack)
{
    if (stack->count != 0)
    {
        stack->top = stack->values + (--stack->count);
        return stack->values[stack->count];
    }

    exit(1);
}

void free_stack(Stack *stack)
{
    FREE_ARRAY(Value, stack->values, stack->capacity);
    init_stack(stack);
}

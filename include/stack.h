#ifndef clox_stack_h
#define clox_stack_h

#include "value.h"

#define STACK_MIN 256

typedef struct
{
    int count;
    int capacity;
    Value *top;
    Value *values;
} Stack;

void init_stack(Stack *stack);
void push_stack(Stack *stack, Value value);
Value pop_stack(Stack *stack);
Value peek_stack(Stack *stack, int distance);
void free_stack(Stack *stack);

#endif

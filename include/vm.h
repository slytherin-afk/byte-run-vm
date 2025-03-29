#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "stack.h"

typedef struct
{
    Chunk *chunk;
    uint8_t *ip;
    Stack stack;
} Vm;

typedef enum
{
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void init_vm();
InterpretResult interpret(const char *source);
void free_vm();
void push(Value value);
Value pop();

#endif

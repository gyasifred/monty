#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int data);
void push_queue(stack_t **stack, unsigned int data);
void pchar(stack_t **stack, unsigned int lin_num);

void check_args_numbs(int argu);
void check_access_file(char *fname);
int check_push_params(char *params);
<<<<<<< HEAD

unsigned int c_stack(stack_s *stack);
=======
void pint(stack_t **stack, unsigned int err_loc);
>>>>>>> 2a15f4fc3e3f7cc641d836da5f766e39d651ea91
#endif

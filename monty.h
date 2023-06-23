#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* Constants */
#define SUCSS_OP		0
#define VALID_PARM		0
#define MIN_ARGS		2
#define METH_STACK		300
#define METH_QUEUE		301

/* Common Errors */
#define ERR_BAD_INST	100
#define ERR_BAD_MALL	101
#define ERR_INVLD_PARM	102

/* Usage Errors */
#define ERR_ARG_USG		200
#define ERR_PUSH_USG	201
#define ERR_PINT_USG	202
#define ERR_POP_USG		203
#define ERR_SWAP_USG	204
#define ERR_ADD_USG		205
#define ERR_SUB_USG		206
#define ERR_DIV_USG		207
#define ERR_DIV_ZRO		208
#define ERR_MUL_USG		209
#define ERR_MOD_USG		210
#define ERR_PCH_USG		211
#define ERR_PCH_EMP		212

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

extern stack_t *head;

void push(stack_t **stack, unsigned int data);
void push_queue(stack_t **stack, unsigned int data);
void pchar(stack_t **stack, unsigned int lin_num);
void check_args_numbs(int argc);
void check_access_file(char *fname);
int check_digit(char *str);
int check_push_params(char *params);
unsigned int c_stack(stack_t *stack);
void pint(stack_t **stack, unsigned int err_loc);
void pstr(stack_t **stack, unsigned int err_loc);
void rotl(stack_t **stack, unsigned int err_loc);
void frees_stack(void);
void handle_error(int errno, char *opcode, unsigned int line, char *buff);
void handle_cerror(int errno, char *opcode, unsigned int line);
void handle_uerror(int errno, unsigned int line);
void handle_more_uerror(int errno, unsigned int line);
void rotr(stack_t **stack, unsigned int err_loc);
void sub(stack_t **stack, unsigned int err_loc);
void swap(stack_t **stack, unsigned int err_Loc);
int handle_execution(char *opcode, char *opparams, unsigned int line, int a);
FILE *open_file(char *filename);
void (*pick_func(char *s))(stack_t **, unsigned int);
void add(stack_t **stack, unsigned int line_numb);
void divide(stack_t **stack, unsigned int line_numb);
void mod(stack_t **stack, unsigned int line_numb);
void mul(stack_t **stack, unsigned int line_numb);
void nop(stack_t **stack, unsigned int line_numb);
void pall(stack_t **stack, unsigned int line_numb);
void pop(stack_t **stack, unsigned int err_loc);

#endif

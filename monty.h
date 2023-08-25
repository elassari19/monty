#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - struct stack
 * @n: n
 * @prev: prev
 * @next: next
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - struct bus
 * @arg: arg
 * @file: file
 * @ln: line ln
 * @lifi: lifi
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *ln;
	int lifi;
}  bus_t;
extern bus_t bus;

/**
 * struct instruction_s - struct instruction
 * @opcode: opcode
 * @f: function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *ln);
void push_item(stack_t **head, unsigned int number);
void print_all(stack_t **head, unsigned int number);
void print_int(stack_t **head, unsigned int number);
int execute(char *ln, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void pop_item(stack_t **head, unsigned int counter);
void swap_item(stack_t **head, unsigned int counter);
void func_add_item(stack_t **head, unsigned int counter);
void func_no_op(stack_t **head, unsigned int counter);
void sub_item(stack_t **head, unsigned int counter);
void div_item(stack_t **head, unsigned int counter);
void multiply_item(stack_t **head, unsigned int counter);
void mode_item(stack_t **head, unsigned int counter);
void print_char(stack_t **head, unsigned int counter);
void print_str(stack_t **head, unsigned int counter);
void rotates_func_top(stack_t **head, unsigned int counter);
void rotates_func_bottom(stack_t **head, __attribute__((unused)) unsigned int counter);
void add_item(stack_t **head, int n);
void add_item_to_queue(stack_t **head, int n);
void print_queue(stack_t **head, unsigned int counter);
void print_top_stack(stack_t **head, unsigned int counter);

#endif

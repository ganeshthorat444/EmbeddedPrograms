

/* we are going to write the program on stack data structure
 * Stack is linear data structure which perfoems operation in perticular order 
 * The order may be LIFO/FIFO
 * Operations mainly contains PUSH
			      PULL
			      ISEMPTY
			      ISFULL
 * Applications 
 * Used in many algorithms like 
	Tower of Hanoi, 
	tree traversals, 
	stock span problem, 
	histogram problem.
 * Other applications can be 
	Backtracking, 
	Knight tour problem, 
	rat in a maze, 
	N queen problem,
	sudoku solver

 * we can implement the stack using two ways 
	1. ARRAY 
	2. LINKED LIST

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int top;
	int limit;
	int* array;
}stack_t;

stack_t* createStack(int limit)
{
	stack_t *stack = (stack_t*)malloc(sizeof(stack_t));
	stack->limit = limit;
	stack->top = -1;
	stack->array = malloc(limit * sizeof(int));
	return stack;
}

void push(stack_t* stack, int val)
{
	if(stack->top == (stack->limit)-1)
	{
		printf("Stack is full !\n");
		return ;
	}
	stack->top += 1;
	stack->array[stack->top] = val;
	printf("Element Pushed = %d\n", stack->array[stack->top]);
		
}

int pop(stack_t* stack)
{
	int val;
	if(stack->top == -1)
	{	
		printf("Stack is empty !\n");
		return -1;
	
	}
	val = stack->array[stack->top];
	stack->top -= 1;
	return val;
}


/* main function*/
int main(void)
{
	int ret = 0;
	printf("STACK implementation using ARRAY !\n");
	
	stack_t* stack = createStack(100);
	
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);

       ret = pop(stack);

	printf("Elemnet poped = %d\n", ret);
	return 0;
}

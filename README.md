# 0x19. C - Stacks, Queues - LIFO, FIFO
>In this repository, Sebastian Carvajal and I implement a Monty code interpreter.

## How does it work?
>Monty's interpreter receives a .m file with line-by-line instructions. Upon receiving the file, the interpreter reads line by line, interprets them and executes them until all the instructions are finished or until an erroneous instruction appears, exiting and indicating the error.

>In particular, this Monty interpreter executes instructions related to a doubly linked list.

## Instructions:
* push - pushes an element to the stack.
* pall - prints all the values on the stack, starting from the top of the stack.
* pint - prints the value at the top of the stack.
* pop -  removes the top element of the stack.
* swap - swaps the top two elements of the stack.
* add - adds the top two elements of the stack.
* nop - doesn’t do anything.
* sub - subtracts the top element of the stack from the second top element of the stack.
* div - divides the second top element of the stack by the top element of the stack.
* mul - multiplies the second top element of the stack with the top element of the stack.
* mod - computes the rest of the division of the second top element of the stack by the top element of the stack.
* pchar - prints the char at the top of the stack, followed by a new line.
* pstr - prints the string starting at the top of the stack, followed by a new line.
* rotl - rotates the stack to the top.
* rotr - rotates the stack to the bottom.
* stack - sets the format of the data to a stack (LIFO). This is the default behavior of the program.
* queue - sets the format of the data to a queue (FIFO).

## Examples:
>/monty$ cat -e 00.m  
push 1$  
push 2$  
push 3$  
pall$  
>/monty$ ./monty 00.m  
3  
2  
1  
>/monty$

>/monty$ cat 06.m  
push 1  
pint  
push 2  
pint  
push 3  
pint  
>/monty$ ./monty 06.m 
1
2
3
>/monty$ 

>/monty$ cat 07.m   
push 1  
push 2  
push 3  
pall  
pop  
pall  
pop  
pall  
pop  
pall  
>/monty$ ./monty 07.m   
3  
2  
1  
2  
1  
1  
/monty$ 


# 0x19. C - Stacks, Queues - LIFO, FIFO
>In this repository, Sebastian Carvajal and I implement a Monty code interpreter.

## How does it work?
>Monty's interpreter receives a .m file with line-by-line instructions. Upon receiving the file, the interpreter reads line by line, interprets them and executes them until all the instructions are finished or until an erroneous instruction appears, exiting and indicating the error.

>In particular, this Monty interpreter executes instructions related to a doubly linked list in order to create and manage stacks and queues.

>Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:  

>**/monty$ cat -e 001.m**  
push 0 Push 0 onto the stack$  
push 1 Push 1 onto the stack$  
$  
push 2$   
push [tab] 3$  
[spaces]pall[space]$  
$  
[spaces]$    
[tabs]$  
push 4$  
pall This is the end of our program. Monty is awesome!$  
**/monty$** 

## Compilation & Output:
>The code was compiled this way:  
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty

>The output is printed on stdout.  
Any error message is printed on stderr

## Instructions or opcodes:
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
>**PUSH & PALL**  
**/monty$ cat -e 00.m**  
push 1$  
push 2$  
push 3$  
pall$  
**/monty$ ./monty 00.m**  
3  
2  
1  
**/monty$**  

>**PINT**  
**/monty$ cat 06.m**  
push 1  
pint  
push 2  
pint  
push 3  
pint  
**/monty$ ./monty 06.m**  
1  
2  
3  
**/monty$**  

>**POP**  
**/monty$ cat 07.m**   
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
**/monty$ ./monty 07.m**   
3  
2  
1  
2  
1  
1  
**/monty$** 

>**ADD**  
**/monty$ cat 12.m**   
push 1  
push 2  
push 3  
pall  
add  
pall  
**/monty$ ./monty 12.m**   
3
2
1
5
1
**/monty$**

>**SUB**  
**/monty$ cat 19.m**   
push 1  
push 2  
push 10  
push 3  
sub  
pall  
**/monty$ ./monty 19.m**   
7  
2  
1  
**/monty$**  

>**PCHAR**  
**/monty$ cat 28.m**   
push 72  
pchar  
**/monty$ ./monty 28.m** 
H
**/monty$**

>**PSTR**  
**/monty$ cat 31.m**   
push 1  
push 2  
push 3  
push 4  
push 0  
push 110  
push 0  
push 108  
push 111  
push 111  
push 104  
push 99  
push 83  
pstr  
**/monty$ ./monty 31.m**   
School  
**/monty$** 


## How can you report an error or solve a question?
> You can contact to authors sending a message through github accounts or an email to Sebastian Garcia <4564@holbertonschool.com> or Sebastian Carvajal <4574@hobertonschool.com>
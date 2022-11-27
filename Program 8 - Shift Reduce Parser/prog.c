/*
Yadul Manoj
https://github.com/man-yadul

Shift reduce parser for the grammar:
S -> (L) | a
L -> L,S | S

Input 1: (a,(a,a)) - Accepted
Input 2: (a,(a,a) - Rejected
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[20], stack[20];
int input_ptr, stack_top;

void main()
{
    input_ptr = 0;
    stack_top = -1;

    printf("Grammar:\nS->(L) | a\nL -> L,S | S\n");
    printf("Enter input string: ");
    scanf("%s", input);
    printf("%-20s%-20s%-20s\n", "Stack", "Input", "Action");
    
    // The loop runs only if either of the flags are set
    // i.e. Either reduction can be done with stack content, or shifting can be done with input 
    int shift, reduce;
    do
    {
        shift = reduce = 0;

        if (stack[0] == 'S' && input[strlen(input) - 1] == ' ')
        {
            printf("String accepted.\n");
            exit(0);
        }

        if (stack[stack_top] == ')' && stack[stack_top - 1] == 'L' && stack[stack_top - 2] == '(')
        {
            reduce = 1;
            stack[stack_top - 2] = 'S';
            stack[stack_top - 1] = '\0';
            stack_top -= 2;
            printf("%-20s%-20s%-20s\n", stack, input, "Reduce to S -> (L)");
        }
        else if (stack[stack_top] == 'a')
        {
            reduce = 1;
            stack[stack_top] = 'S';
            stack[stack_top + 1] = '\0';
            printf("%-20s%-20s%-20s\n", stack, input, "Reduce to S -> a");
        }
        else if (stack[stack_top] == 'S' && stack[stack_top - 1] == ',' && stack[stack_top - 2] == 'L')
        {
            reduce = 1;
            stack[stack_top - 2] = 'L';
            stack[stack_top - 1] = '\0';
            stack_top -= 2;
            printf("%-20s%-20s%-20s\n", stack, input, "Reduce to L -> L, S");
        }
        else if (stack[stack_top] == 'S')
        {
            reduce = 1;
            stack[stack_top] = 'L';
            stack[stack_top + 1] = '\0';
            printf("%-20s%-20s%-20s\n", stack, input, "Reduce to L -> S");
        }
        else
        {
            if (input[input_ptr] != '\0')
            {
                shift = 1;
                stack_top++;
                stack[stack_top] = input[input_ptr];
                stack[stack_top + 1] = '\0';
                input[input_ptr] = ' ';
                input_ptr++;
                printf("%-20s%-20s%-20s\n", stack, input, "Shift");
            }
        }
    } while ((shift == 1 || reduce == 1));

    printf("String rejected.\n");
}

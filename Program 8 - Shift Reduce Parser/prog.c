/*
Yadul Manoj
https://github.com/man-yadul

Shift reduce parser

Sample input for grammar:
S -> (L) | a
L -> L,S | S
[THE PRODUCTIONS MUST BE ENTERED WITHOUT ANY SPACES]

Enter no. of productions: 4
Enter the productions:
S=(L)
S=a  
L=L,S
L=S
Enter the input string: (a,(a,a))
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char productions[10][20], input[20], stack[20];
int input_ptr, stack_top, no_of_productions;

void main()
{
    input_ptr = 0;
    stack_top = -1;

    printf("Enter no. of productions: ");
    scanf("%d", &no_of_productions);
    printf("Enter the productions:\n");
    for (int i = 0; i < no_of_productions; i++)
        scanf("%s", productions[i]);
    printf("Enter the input string: ");
    scanf("%s", input);
    printf("%-20s%-20s%-20s\n", "Stack", "Input", "Action");

    // The loop runs only if either reduction can be done with stack content, or shifting can be done with input
    int shift, reduce;
    do
    {
        // Variables shift and reduce is set to 1 if any of the operations can be done
        shift = 0;
        reduce = 1;

        // Accept the string if bottom of the stack contains only the starting symbol and the input buffer is empty
        if (stack[0] == productions[0][0] && strlen(stack) == 1 && input[strlen(input) - 1] == ' ')
        {
            printf("String accepted.\n");
            exit(0);
        }

        int i;
        for (i = 0; i < no_of_productions; i++)
        {
            reduce = 1;
            
            /*
            Loop to check if the stack contents match the RHS of any production
            Stack iterations: Starting point - stack top; Ending point - bottom of the stack (index 0) (worst case)
            The stack iterations run as long as there are enough characters to process in the RHS of the production
            k >= 2: The RHS of the production begins at index 2
            After match, variable i will contain the index of the production
            */
            for (int j = stack_top, k = strlen(productions[i]) - 1; j >= 0, k >= 2; j--, k--)
            {
                // Character mismatch; no reduction
                if (stack[j] != productions[i][k])
                    reduce = 0;
            }

            if (reduce == 1)
                break;
        }

        if (reduce == 1)
        {
            int j, k;

            // Move to the index of the first symbol in the set of matched symbols in the stack
            for (j = stack_top, k = strlen(productions[i]) - 1; j >= 0, k >= 2; j--, k--)
                ;

            // Replace the first symbol with the starting symbol of the production 
            // j + 1: After running the above loop, j points to one less than the postion we need to access
            stack[j + 1] = productions[i][0];

            // Replace the next character to \0 to mark the end of the stack (To avoid unnecessary code for stack content deletion)
            stack[j + 2] = '\0';

            // Decrement stack top with the number of characters reduced
            // -2: First two characters of the production are not processed (Starting symbol of the production and '=')
            // -1: To match zero-indexing
            stack_top -= strlen(productions[i]) - 2 - 1;

            printf("%-20s%-20sReduce to %s\n", stack, input, productions[i]);
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
    } while (shift == 1 || reduce == 1);

    printf("String rejected.\n");
}

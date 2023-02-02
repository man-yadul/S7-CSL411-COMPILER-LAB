/*
Yadul Manoj
github.com/man-yadul

NFA to DFA

THE PROGRAM DOES NOT SUPPORT EPSILON TRANSITIONS

Refer input.png for input details
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// No. of states in the NFA
int states;
// No. of inputs in the NFA
int inputs;
// NFA entered as an NxN matrix with the 2D matrices stacked for each input
int transitions[10][10][10];
// Transition table for the NFA
char nfa_table[10][10][10];
// Transition table for the DFA
char final_dfa[10][10][10];

void main()
{
    printf("Enter no. of states: ");
    scanf("%d", &states);

    printf("Enter no. of input symbols: ");
    scanf("%d", &inputs);

    for (int i = 0; i < inputs; i++)
    {
        printf("Enter NFA matrix for input %d:\n", i + 1);
        for (int j = 0; j < states; j++)
        {
            for (int k = 0; k < states; k++)
            {
                scanf("%d", &transitions[i][j][k]);
            }
        }
    }

    // Create the transition table for the NFA
    char str[10];
    for (int i = 0; i < states; i++)
    {
        for (int j = 0; j < states; j++)
        {
            for (int k = 0; k < inputs; k++)
            {
                if (transitions[k][i][j] == 1)
                {
                    sprintf(str, "q%d", j);
                    if (strcmp(nfa_table[i][k], str) != 0)
                    {
                        strcat(nfa_table[i][k], str);
                    }
                }
            }
        }
    }

    // Conversion to DFA starts here. A queue is maintained to keep track of the new states that are found.
    char queue[20][10];
    int front = 0;
    int rear = 0;
    // Total rows of the final DFA table
    int rows = 0;

    for (int i = 0; i < 20; i++)
        strcpy(queue[i], "");
    strcpy(queue[rear], "q0");
    rear++;
    strcpy(final_dfa[rows][0], "q0");

    // Repeat until queue is empty
    while (strcmp(queue[front], "") != 0)
    {
        // Keeps track of new rows of DFA table when new states are added
        int temp_rows = rows;
        // Contains the new states that are found for an input symbol transition for each state
        char new_states[20];

        // Reset the new states list
        for (int i = 0; i < 20; i++)
            strcpy(new_states, "");

        // For each input symbol
        for (int j = 0; j < inputs; j++)
        {
            // Reset the new states list
            for (int i = 0; i < 20; i++)
                strcpy(new_states, "");

            // Loop to find the transitions for each input of the current state in the front of the queue
            // i = 1; i += 2: For each sub-state in the current state - i.e., q0, q1, q2 in q0q1q2
            for (int i = 1; i < strlen(queue[front]); i += 2)
            {
                if (isdigit(queue[front][i]))
                {
                    int n = queue[front][i] - '0';

                    // Loop to find the transitions of the current state that is being checked
                    for (int l = 1; l < strlen(nfa_table[n][j]); l += 2)
                    {
                        int num1;
                        if (isdigit(nfa_table[n][j][l]))
                        {
                            num1 = nfa_table[n][j][l] - '0';
                        }

                        // Loop to check if a transition creates duplicate states;
                        // eg:- if q0q1 has input 0 transitions as q0 -> q1 and q1 -> q1, q1 need not be added twice to new_states
                        int flag2 = 0;
                        int num2;
                        for (int m = 1; m < strlen(new_states); m += 2)
                        {
                            if (isdigit(new_states[m]))
                            {
                                num2 = new_states[m] - '0';
                                if (num1 == num2)
                                    flag2 = 1;
                            }
                        }

                        if (flag2 == 0)
                        {
                            char temp[20];
                            sprintf(temp, "q%d", num1);
                            strcat(new_states, temp);
                        }
                    }
                }
            }

            // Sort the new states list in ascending order of state number
            int temp_states[20];
            int temp_index = 0;
            for (int d = 0; d < strlen(new_states); d++)
            {
                if (isdigit(new_states[d]))
                {
                    temp_states[temp_index++] = new_states[d] - '0';
                }
            }

            for (int q = 0; q < temp_index; q++)
            {
                for (int r = 0; r < temp_index - q - 1; r++)
                {
                    if (temp_states[r] > temp_states[r + 1])
                    {
                        int swap = temp_states[r];
                        temp_states[r] = temp_states[r + 1];
                        temp_states[r + 1] = swap;
                    }
                }
            }

            char tempstr[20];
            strcpy(new_states, "");
            for (int q = 0; q < temp_index; q++)
            {
                sprintf(tempstr, "q%d", temp_states[q]);
                strcat(new_states, tempstr);
            }

            // Check if new state is already in queue, if not, add it to queue
            int flag = 0;
            for (int a = 0; a < rear; a++)
            {
                if (strcmp(queue[a], new_states) == 0)
                {
                    flag = 1;
                }
            }

            if (flag == 0)
            {
                strcpy(queue[rear], new_states);
                rear++;
                // Add new state to the next row of the final DFA table
                strcpy(final_dfa[++temp_rows][0], new_states);
            }

            strcpy(final_dfa[rows][j + 1], new_states);
        }

        rows++;
        front++;
    }

    printf("\nDFA:\n");
    printf("%-10s|", " ");
    for (int i = 0; i < inputs; i++)
        printf("Input %-4d|", i + 1);
    printf("\n");
    for (int i = 0; i < 11 * (inputs + 1); i++)
        printf("%s", "=");
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < inputs + 1; j++)
        {
            printf("%-10s|", final_dfa[i][j]);
        }
        printf("\n");
    }
}

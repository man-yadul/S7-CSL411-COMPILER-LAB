/*
Yadul Manoj
github.com/man-yadul

Recursive descent parser for a given grammar
Grammar -
S -> aABe
A -> bA'
A' -> bcA' | epsilon (#)
B -> d

Input 1: abbcde - accepted
Input 2: abde - accepted
Input 3: abce - rejected
*/

#include <stdio.h>
#include <stdlib.h>

char input[10];
int i = 0, accept = 0;

void S();
void A();
void A_dash();
void B();

void S()
{
    if (input[i] == 'a')
    {
        i++;
        A();
        B();
        if (input[i] == 'e' && input[i + 1] == '\0')
        {
            i++;
            accept = 1;
        }
    }
}

void A()
{
    if (input[i] == 'b')
    {
        i++;
        A_dash();
    }
    else
    {
        printf("Rejected.\n");
        exit(0);
    }
}

void A_dash()
{
    if (input[i] == 'b')
    {
        i++;
        if (input[i] == 'c')
        {
            i++;
            A_dash();
        }
        else
        {
            printf("Rejected.\n");
            exit(0);
        }
    }
}

void B()
{
    if (input[i] == 'd')
    {
        i++;
    }
    else
    {
        printf("Rejected.\n");
        exit(0);
    }
}

void main()
{
    printf("Enter input string: ");
    scanf("%s", input);

    S();
    
    if (accept == 1)
        printf("Accepted.\n");
    else
        printf("Rejected.\n");
}

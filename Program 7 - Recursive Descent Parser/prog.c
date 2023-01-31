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
#include <string.h>

char input[10];
int i = 0, valid = 1;

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
        if (input[i] == 'e')
            i++;
        else  
            valid = 0;
    }
    else
        valid = 0;
}

void A()
{
    if (input[i] == 'b')
    {
        i++;
        A_dash();
    }
    else
        valid = 0;
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
            valid = 0;
    }
}

void B()
{
    if (input[i] == 'd')
        i++;
    else
        valid = 0;
}

void main()
{
    printf("Enter input string: ");
    scanf("%s", input);

    S();

    // All productions checked and input is empty
    if (valid == 1 && i == strlen(input))
        printf("Accepted.\n");
    else  
        printf("Rejected.\n"); 
}

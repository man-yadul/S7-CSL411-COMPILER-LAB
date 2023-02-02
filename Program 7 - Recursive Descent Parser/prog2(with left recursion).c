/*
Yadul Manoj
github.com/man-yadul

Recursive descent parser for a given grammar

Grammar -
E -> E + T | T
T -> T * F | F
F -> (E) | id

Recursive descent parsers do not support left recursive grammar.
Left recursion must be removed before implementing the grammar in the program.

Steps to remove left recursion - 
A Grammar G (V, T, P, S) is left recursive if it has a production in the form:
A → Aα | β

Eliminate left recursion by replacing the production with:
A → βA′
A′ → αA′| ε

New grammar -
E -> TE'
E' -> +TE' | ε
T -> FT'
T' -> *FT' | ε
F -> (E) | id

a, (a), a+(a*a), a+a*a , a+a+a*a+a - accepted
a++a, a***a, +a, a*, ((a - rejected
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char input[10];
int i = 0, valid = 1;

void E();
void E_dash();
void T();
void T_dash();
void F();

void E()
{
    T();
    E_dash();
}

void E_dash()
{
    if (input[i] == '+')
    {
        i++;
        T();
        E_dash();
    }
}

void T()
{
    F();
    T_dash();
}

void T_dash()
{
    if (input[i] == '*')
    {
        i++;
        F();
        T_dash();
    }
}

void F()
{
    if (input[i] == '(')
    {
        i++;
        E();
        if (input[i] == ')')
            i++;
        else  
            valid = 0;
    }
    else if (isalnum(input[i]))
        i++;
    else
        valid = 0;
}

void main()
{
    printf("Enter input string: ");
    scanf("%s", input);

    E();

    if (valid == 1 && i == strlen(input))
        printf("Accepted.\n");
    else  
        printf("Rejected.\n");
}

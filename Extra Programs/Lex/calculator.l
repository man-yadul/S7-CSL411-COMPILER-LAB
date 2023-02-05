/*
https://github.com/man-yadul

Lex program of a simple calculator

Sample input and output:
user@DESKTOP-RTDC9H3:~$ lex calculator.l
user@DESKTOP-RTDC9H3:~$ gcc lex.yy.c -lfl
user@DESKTOP-RTDC9H3:~$ ./a.out
10+3

Result: 13
user@DESKTOP-RTDC9H3:~$ ./a.out
10-20

Result: -10
user@DESKTOP-RTDC9H3:~$ ./a.out
4*5

Result: 20
user@DESKTOP-RTDC9H3:~$ ./a.out
50/5

Result: 10
*/

%{
	#include <stdio.h>
	#include <string.h>

	// flag is used to decide where the input numbers are to be stored as operands
	int flag = 0;
	char operand1[20];
	char operand2[20];
	char operand[5];
%}

%%
[0-9]+	{
	if (flag == 0)
		strcpy(operand1, yytext);
	else
		strcpy(operand2, yytext);	
}

[\+\-\*/]	{
	strcpy(operand, yytext);
	flag = 1;
}
%%

void main()
{
	yylex();

	int op1 = atoi(operand1);
	int op2 = atoi(operand2);
	
	if (strcmp(operand, "+") == 0)
		printf("Result: %d\n", op1 + op2);
	else if (strcmp(operand, "-") == 0)
		printf("Result: %d\n", op1 - op2);
	else if (strcmp(operand, "*") == 0)
		printf("Result: %d\n", op1 * op2);
	else 
		printf("Result: %d\n", op1 / op2);
}

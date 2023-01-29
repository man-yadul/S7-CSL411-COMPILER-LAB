/*
https://github.com/man-yadul

YACC Program to find the sum of two numbers

The program finds the sum of exactly two numbers only  
The input MUST NOT have any spaces between the numbers and plus sign

Valid input:

123+431        [Two numbers with a plus sign between them (no spaces)]

Sample input and output:

user@DESKTOP-RTDC9H3:~$ yacc -d p7.y
user@DESKTOP-RTDC9H3:~$ lex p7.l
user@DESKTOP-RTDC9H3:~$ gcc lex.yy.c y.tab.c -w
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter expression:
123+3241
3364

user@DESKTOP-RTDC9H3:~$ ./a.out
Enter expression:
123+321
444
*/

%{
	#include "y.tab.h"
	extern int yylval;
%}

%%
[0-9]+	{
	yylval = atoi(yytext);
	return NUMBER;
}
\+	return PLUS;
%%

int yywrap()
{
	return 1;
}

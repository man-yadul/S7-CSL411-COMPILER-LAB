/*
https://github.com/man-yadul

YACC Program to check the syntax of a for loop

The program only checks the syntax of a for loop header 
The input MUST NOT have any spaces between the tokens

Valid inputs:

for(;;)				[Loop header with no initialization statement, no test expression, no update statement]

for(i=0;i<n;i++)		[Loop header with all the statements and expressions]

for(i=0,j=0;i<n,j<n;i++,j--)	[Loop header with multiple statements and expressions]

for(;i<n;)			[Loop header with only the test expression]

for(i=0;;)			[Loop header with only the initialization statement]

for(;;i++)			[Loop header with only the update statement]

				[Any combination of the above three inputs]

Sample input and output:

user@DESKTOP-RTDC9H3:~$ yacc -d p6.y
user@DESKTOP-RTDC9H3:~$ lex p6.l
user@DESKTOP-RTDC9H3:~$ gcc lex.yy.c y.tab.c -w
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
for(i=0;i<n;i++)
Valid.
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
for(;;)
Valid.
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
for(i=0,j=0;i<n,j<=n;i++,j--)
Valid.
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
for(;i<=n;)
Valid.
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
for(i=0;i<n)
Invalid.
*/

%{
#include "y.tab.h"
%}

%%
for					return FOR;
[\(\)]					return PARANTHESIS;
[a-zA-Z0-9]*				return OPERAND;
"="|"<"|">"|">="|"<="|"=="|"++"|"--"	return OPERATOR;
\;					return SEMICOLON;
,					return COMMA;
\n					return NEWLINE;
.					;
%%

int yywrap()
{
	return 1;
}

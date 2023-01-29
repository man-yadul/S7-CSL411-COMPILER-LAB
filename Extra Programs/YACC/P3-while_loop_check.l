/*
https://github.com/man-yadul

YACC Program to check the syntax of a while loop

The input MUST NOT have any spaces between the tokens
Newline character (Enter key) is accepted

Valid inputs:

while(a<b)		[Loop with two operands and no body]

while(a<b)		[Loop with two operands and body (curly brackets on separate lines)]
{
}

while(a<b)		[Loop with two operands and body (curly brackets on the same line)]
{}

while(a)		[Loop with a single operand and no body]

while(a)		[Loop with a single operand and body (curly brackets on separate lines)]
{
}

while(a)		[Loop with a single operand and body (curly brackets on the same line)]
{}

Sample input and output:

user@DESKTOP-RTDC9H3:~$ yacc -d p5.y
user@DESKTOP-RTDC9H3:~$ lex p5.l
user@DESKTOP-RTDC9H3:~$ gcc lex.yy.c y.tab.c -w
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
while(ab<5)
Valid.
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
while(a)
{
}
Valid.
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
while(a==b)
{}
Valid.
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
while(a
Invalid.
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
while(a)
{

Invalid.
*/

%{
	#include "y.tab.h"
%}

%%
while			return WHILE;
[\(\)]			return PARANTHESIS;
[a-zA-Z0-9]+		return OPERAND;
">"|"<"|">="|"<="|"=="	return RELOP;
"{"|"}"			return CURL_BRACKET;
\n			return NEWLINE;
.			;
%%

int yywrap()
{
	return 1;
}

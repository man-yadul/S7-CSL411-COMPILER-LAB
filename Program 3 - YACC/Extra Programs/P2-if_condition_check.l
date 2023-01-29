/*
https://github.com/man-yadul

YACC Program to check the validity of an if condition

The if keyword, operands and operator MUST NOT be entered with spaces between them.
The if condition can only have one operator (NO NESTED CONDITION CHECKING).

Valid input:
if(a<b)		[if condition with two operands and no body]

Sample input and output:
user@DESKTOP-RTDC9H3:~$ vi p4.l
user@DESKTOP-RTDC9H3:~$ yacc -d p4.y
user@DESKTOP-RTDC9H3:~$ lex p4.l
user@DESKTOP-RTDC9H3:~$ gcc lex.yy.c y.tab.c -w
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
if(a==b)

Valid.
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
if(a<b)

Valid.
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
if(abc>=bca)

Valid.
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
ifif
Invalid.
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
if(1<4)

Valid.
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter string:
if(1<4

Invalid.
*/

%{
	#include "y.tab.h"
%}

%%
if			return IF;
[\(\)]			return PARANTHESIS;
[a-zA-Z0-9]+		return OPERAND;
"<"|">"|">="|"<="|"=="	return RELOP;	
.			;
%%

int yywrap()
{
	return 1;
}

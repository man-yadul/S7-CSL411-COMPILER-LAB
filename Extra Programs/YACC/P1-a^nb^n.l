/*
https://github.com/man-yadul

YACC Program to identify strings of the pattern a^nb^n, n >= 0, and the length of the recognized string

Sample input and output:

user@DESKTOP-RTDC9H3:~$ yacc -d p3.y
user@DESKTOP-RTDC9H3:~$ lex p3.l
user@DESKTOP-RTDC9H3:~$ gcc lex.yy.c y.tab.c -w
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter the string:
ab
Valid.
Length: 2
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter the string:
aabb
Valid.
Length: 4
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter the string:

Valid.
Length: 0
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter the string:
aaabb
Invalid.
*/

%{
	#include "y.tab.h"
%}

%%
[aA]	return A;
[bB]	return B;
.	;
%%

int yywrap()
{
	return 1;
}

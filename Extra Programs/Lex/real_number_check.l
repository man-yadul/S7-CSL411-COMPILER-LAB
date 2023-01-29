/*
Yadul Manoj
https://github.com/man-yadul

Lex program to check if a number is a real number or not.
Valid input - 3, 3.14, 0.14, .14

Sample output:
user@DESKTOP-RTDC9H3:~$ vi p.l
user@DESKTOP-RTDC9H3:~$ lex p.l
user@DESKTOP-RTDC9H3:~$ gcc lex.yy.c -lfl
user@DESKTOP-RTDC9H3:~$ ./a.out
3.14

Real number.
user@DESKTOP-RTDC9H3:~$ ./a.out
.14

Real number.
user@DESKTOP-RTDC9H3:~$ ./a.out
asf
asf
Not a real number.
user@DESKTOP-RTDC9H3:~$ ./a.out
0.44jh

Not a real number.
*/

%{
#include <stdio.h>
int flag = 0;
%}

%%
[0-9]*(\.)?[0-9]+       flag = 1;
.                       flag = 0;
%%

void main()
{
        yylex();
        if (flag == 1)
                printf("Real number.\n");
        else
                printf("Not a real number.\n");
}

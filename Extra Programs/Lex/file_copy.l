/*
https://github.com/man-yadul

Lex program to copy contents of one file to another

Sample input and output:
user@DESKTOP-RTDC9H3:~$ lex file_copy.l
user@DESKTOP-RTDC9H3:~$ gcc lex.yy.c -lfl
user@DESKTOP-RTDC9H3:~$ cat input.txt
#include <stdio.h>

void main()
{
        printf(Hello.\n");
}
user@DESKTOP-RTDC9H3:~$ cat output.txt
user@DESKTOP-RTDC9H3:~$ ./a.out
user@DESKTOP-RTDC9H3:~$ cat output.txt
#include <stdio.h>

void main()
{
        printf(Hello.\n");
}
*/

%%
.*\n	fprintf(yyout, "%s", yytext);
%%

void main()
{
	yyin = fopen("input.txt", "r");
	yyout = fopen("output.txt", "w");
	yylex();
}

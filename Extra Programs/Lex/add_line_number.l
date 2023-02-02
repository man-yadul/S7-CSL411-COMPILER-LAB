/*
Lex program to add line numbers to an input file

Sample input and output:
user@DESKTOP-RTDC9H3:~$ lex linecount.l
user@DESKTOP-RTDC9H3:~$ gcc lex.yy.c -lfl
user@DESKTOP-RTDC9H3:~$ ./a.out
1 #include <stdio.h>
2
3 void main()
4 {
5       printf("Hello.\n");
6 }
*/

%{
	int count = 1;
%}

%%
.*\n	printf("%d %s", count++, yytext);
%%

void main()
{
	yyin = fopen("input.txt", "r");
	yylex();
}

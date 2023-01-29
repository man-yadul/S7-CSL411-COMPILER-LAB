/*
Yadul Manoj
https://github.com/man-yadul

Lex Program to check if a token is an identifier or a keyword.

Valid input keywords: void, main, if, else, break, continue, const, final, switch, for, while, include
Accepts all valid identifiers.

The program accepts a line of tokens (or a single token) and checks each token indvidually.

Sample input and output:

user@DESKTOP-RTDC9H3:~$ vi prog.l
user@DESKTOP-RTDC9H3:~$ lex prog.l
user@DESKTOP-RTDC9H3:~$ gcc lex.yy.c -lfl
user@DESKTOP-RTDC9H3:~$ ./a.out
Enter tokens:
void main abcd _dasd123 12312dfa
void is a keyword.
main is a keyword.
abcd is an identifier.
_dasd123 is an identifier.
12312dfa is not an identifier. 
*/

%{
	#include <stdio.h>
%}

%%
void|main|if|else|break|continue|const|final|switch|for|while|include	{printf("%s is a keyword.\n", yytext);}

[a-zA-Z_]+[0-9a-zA-Z_]*	{printf("%s is an identifier.\n", yytext);}

[0-9]+[0-9a-zA-Z_]*	{printf("%s is not an identifier.\n", yytext);}

[ \t\n]	;
%%

void main()
{
	printf("Enter tokens:\n");
	yylex();
}

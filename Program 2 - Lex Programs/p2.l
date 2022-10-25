%{
#include <stdio.h>
int i;
%}

%%
[a-z] {
	yytext[0] = yytext[0] - 32;
	printf("%c", yytext[0]);
}
%%

int main()
{
	yylex();
	return 0;
}

int yywrap()
{
	return 1;
}

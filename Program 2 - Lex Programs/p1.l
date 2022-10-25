%{
	#include<stdio.h>
	int lines = 0, words = 0, letters = 0, num = 0, spl_char = 0, total = 0;
%}
%%
\n { lines++; words++;}
[\t ' '] words++;
[a-zA-Z] letters++;
[0-9] num++;
. spl_char++;
%%

int main(void)
{
    yylex();
	total = letters + num + spl_char;
	printf("\n%d lines.", lines);
	printf("\n%d words.", words);
	printf("\n%d characters.\n",total);
}

int yywrap() 
{
	return 1;
}

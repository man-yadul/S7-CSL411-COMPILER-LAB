%{
	#include <stdio.h>
	int vowels = 0;
	int consonants = 0;
%}

%%
[aeiouAEIOU] {vowels++;}
[\t ] {ECHO;}
. {consonants++;}
%%

int main()
{
	yylex();
	printf("Vowels: %d\n", vowels);
	printf("Consonants: %d\n", consonants);
	return 0;
}

int yywrap()
{
	return 1;
}

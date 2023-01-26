%{
	#include <stdio.h>
	int valid = 1;
%}

%token A B NL

%%
start: S NL;
S: A S B |;
%%

int yyerror()
{
	valid = 0;
	printf("Invalid.\n");
	return 0;
}

void main()
{
	printf("Enter the string:\n");
	yyparse();

	if (valid)
	{
		printf("Valid.\n");
	}
}

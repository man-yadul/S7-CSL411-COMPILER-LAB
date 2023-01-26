%{
	#include <stdio.h>
	int valid = 1;
%}

%token IF PARANTHESIS OPERAND RELOP

%%
start: IF PARANTHESIS OPERAND RELOP OPERAND PARANTHESIS;
%%

int yyerror()
{
	valid = 0;
	printf("Invalid.\n");
	return 1;
}

void main()
{
	printf("Enter string:\n");
	yyparse();

	if (valid)
		printf("Valid.\n");
}

%{
	#include <stdio.h>
%}

%token NUMBER PLUS

%%
start: NUMBER PLUS NUMBER {printf("%d\n", $1 + $3);}
%%

int yyerror()
{
	return 1;
}

void main()
{
	printf("Enter expression:\n");
	yyparse();
}

%{
	#include <stdio.h>
	int valid = 1;
	int count = 0;
%}

%token A B

%%
start: S;
S: A S B {count += 2;} |;
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
		printf("Valid.\nLength: %d\n", count);
	}
}

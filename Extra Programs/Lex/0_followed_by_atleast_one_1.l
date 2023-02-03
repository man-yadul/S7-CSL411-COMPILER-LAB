/*
https://github.com/man-yadul

Lex program to accept strings containing 0s and 1s where every 0 is followed by at least one 1
*/

%{
	int valid = 0;
%}

%%
(0?1)*	valid = 1;
.	{valid = 0; return 0;}
%%

void main()
{
	yylex();
	if (valid)
		printf("valid.");
}

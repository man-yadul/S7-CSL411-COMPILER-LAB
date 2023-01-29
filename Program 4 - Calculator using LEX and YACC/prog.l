%{
	#include "y.tab.h"
	extern int yylval;
%}

%%
[0-9]+ {
	yylval=atoi(yytext);
    	return NUMBER;
}
[ \t] 	;
.	return yytext[0];
%%

int yywrap()
{
	return 1;
}

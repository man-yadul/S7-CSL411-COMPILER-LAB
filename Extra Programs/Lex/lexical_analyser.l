/*
https://github.com/man-yadul

Lexical Analyser

Supports comments, variable declarations, and printf statements.
*/

%{
	#include <stdio.h>
%}

%%
"//"[ \t]*(.)*						printf("%s - Comment\n", yytext);
"/*"(\n)*[a-zA-Z0-9\n]*"*/"				printf("%s - Comment\n", yytext);
void|main|int|char|float|double|include|printf|stdio\.h	printf("%s - Keyword\n", yytext);	  
[#<>(),;{}\[\]]						printf("%s - Delimiter\n", yytext);
[+-=*/]							printf("%s - Operator\n", yytext);
[a-zA-Z_]+[a-zA-Z0-9_]*					printf("%s - Identifier\n", yytext);
[+-]?[0-9]*(\.)?[0-9]+					printf("%s - Literal\n", yytext);
\"[a-zA-Z]*\"						printf("%s - String literal\n", yytext);
%%

void main()
{
	yyin = fopen("input.txt", "r");
	yylex();
}

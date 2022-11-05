%{
    #include <stdio.h>
    int valid = 1;
%}

%token digit letter

%%
start: letter s
s: letter s | digit s |;
%%

int yyerror()
{
    printf("Invalid identifier.\n");
    valid = 0;
    return 0;
}

int main()
{
    printf("Enter identifier: ");
    yyparse();

    if(valid)
    {
        printf("Valid identifier.\n");
    }
}

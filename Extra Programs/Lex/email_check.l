/*
https://github.com/man-yadul

Lex program to check the validity of an email address

Sample input and output:
user@DESKTOP-RTDC9H3:~$ lex email.l
user@DESKTOP-RTDC9H3:~$ gcc lex.yy.c -lfl
user@DESKTOP-RTDC9H3:~$ ./a.out
ok@12.com
ok@12.com
Invalid.
user@DESKTOP-RTDC9H3:~$ ./a.out
ok@asd.com

Valid.
user@DESKTOP-RTDC9H3:~$ ./a.out
ok@12.net
ok@12.net
Invalid.
user@DESKTOP-RTDC9H3:~$ ./a.out
asfdasq241@ojasdas.org

Valid.
*/

%{
	int valid = 0;
%}

%%
[a-zA-Z0-9_.]+@[a-zA-Z]+(".com"|".net"|".org")	{valid = 1;}
%%

void main()
{
	yylex();
	if(valid)
		printf("Valid.\n");
	else
		printf("Invalid.\n");
}

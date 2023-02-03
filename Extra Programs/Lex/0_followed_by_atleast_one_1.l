/*
https://github.com/man-yadul

Lex program to accept strings containing 0s and 1s where every 0 is followed by at least one 1

Sample input and output:-
user@DESKTOP-RTDC9H3:~$ lex r.l
user@DESKTOP-RTDC9H3:~$ gcc lex.yy.c -lfl
user@DESKTOP-RTDC9H3:~$ ./a.out
010101

valid.user@DESKTOP-RTDC9H3:~$ ./a.out
11100
user@DESKTOP-RTDC9H3:~$ ./a.out
010101011111

valid.user@DESKTOP-RTDC9H3:~$ ./a.out
0101010000
user@DESKTOP-RTDC9H3:~$ ./a.out
00001010101
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

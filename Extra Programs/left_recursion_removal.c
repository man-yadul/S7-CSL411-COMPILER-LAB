/*
Yadul Manoj
https://github.com/man-yadul

Removal of Left Recursion in grammars

The program will not work with inputs with:
1. Grammars entered with spaces between each character
2. β consisting of more than a single terminal or a non-terminal
3. Indirect left recursive grammars (new left recursive grammars generated after removing left recursion)

Left recursion:-
If we have the left-recursive production-
A → Aα | β where β does not begin with an A.
Then, we can eliminate left recursion by replacing the production with-
A → βA’
A’ → αA’ | ∈

Sample input and output:
Enter no. of productions: 2
A=ABd|Aa|a
B=Be|b

Grammar after removal of left recursion:
A=aA'
A'=BdA'|aA'|$
B=bB'

Enter no. of productions: 1
Enter the productions:
E=E+E|E*E|a

Grammar after removal of left recursion:
E=aE'
E'=+EE'|*EE'|$

Enter no. of productions: 3
Enter the productions:
E=E+T|T
T=T*F|F
F=a

Grammar after removal of left recursion:
E=TE'
E'=+TE'|$
T=FT'
T'=*FT'|$
F=a
*/

#include <stdio.h>
#include <string.h>

int no_of_prodns;
char prodns[10][20];

void main()
{
    printf("Enter no. of productions: ");
    scanf("%d", &no_of_prodns);
    printf("Enter the productions:\n");
    for (int i = 0; i < no_of_prodns; i++)
        scanf("%s", prodns[i]);

    printf("\nGrammar after removal of left recursion:\n");
    // Iterate through each production
    for (int i = 0; i < no_of_prodns; i++)
    {
        // Check if production is left recursive; i.e. leftmost character of RHS matches with the starting symbol of production
        if (prodns[i][2] == prodns[i][0])
        {
            // Write the current production as A -> βA’ (β is the last character of the production: prodns[i][strlen(prodns[i][0]) - 1])
            printf("%c=%c%c\'\n", prodns[i][0], prodns[i][strlen(prodns[i]) - 1], prodns[i][0]);
            printf("%c\'=", prodns[i][0]);
            for (int j = 2; j < strlen(prodns[i]) - 1; j++)
            {
                // Skip any non-terminal with similar production symbol (allow the same symbol to occur after the starting postion of the RHS)
                if (prodns[i][j] == prodns[i][0] && (prodns[i][j - 1] == '=' || prodns[i][j - 1] == '|'))
                    continue;
                else if (prodns[i][j] == '|')
                {
                    // Last | of the grammar
                    if (j == strlen(prodns[i]) - 2)
                        printf("%c\'|$\n", prodns[i][0]);
                    else  
                        printf("%c\'|", prodns[i][0]);
                }
                else  
                    printf("%c", prodns[i][j]);
            }
        }
        else
        {
            printf("%s\n", prodns[i]);
        }
    }
}

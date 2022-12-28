/*
Yadul Manoj
https://github.com/man-yadul

Intermediate Code Generation

The input can only contain expressions WITHOUT parantheses
a=b+c*d - Valid     a=b+(c*d) - Invalid

Sample input and output:
Enter the expression: a=b/d+c*e-f/g+q
Intermediate code:
Z=b/d
Y=c*e
X=f/g
W=Z+Y
V=W-X
U=V+q
a=U
*/

/*
Working: The RHS of the expression is reduced by substituting an operand for every subexpression
e.g.-
a=b/d+c*e-f/g+q
a=Z+c*e-f/g+q   (Z=b/d)
a=Z+Y-f/g+q     (Y=c*e)
a=Z+Y-X+q       (X=f/g)
a=W-X+q         (W=Z+Y)
a=V+q           (V=W-X)
a=U             (U=V+q)
*/

#include <stdio.h>
#include <string.h>

char exprsn[20];
char temp_var = 'Z';

void main()
{
    printf("Enter the expression: ");
    scanf("%s", exprsn);

    printf("Intermediate code:\n");

    // The loop runs until the RHS of the expression is reduced to exactly one operand
    // e.g. a=U - strlen(exprsn) = 3
    while (strlen(exprsn) > 3)
    {
        // Un-comment the below statement to see how the original string is modified
        // printf("%s\n", exprsn);

        // flag is set to 1 when a subexpression is reduced
        int flag = 0;

        if (flag != 1)
        {
            for (int i = 0; i < strlen(exprsn); i++)
            {
                // '/' and '*' given together for equal precedence
                if (exprsn[i] == '/' || exprsn[i] == '*')
                {
                    printf("%c=%c%c%c\n", temp_var, exprsn[i - 1], exprsn[i], exprsn[i + 1]);
                    
                    // Substitute a new operand in the place of the subexpression
                    // e.g. - a=b+c*d-e -> a=b+Z*d-e 
                    // (The final expression must be a=b+Z-e. The *d is removed in the below loop)
                    exprsn[i - 1] = temp_var;
                    temp_var--;

                    // Shift and replace with the characters to the right of the subexpression 
                    for (int j = i; exprsn[j] != '\0'; j++)
                        exprsn[j] = exprsn[j + 2]; 
                    
                    flag = 1;
                    break;
                }
            }
        }

        if (flag != 1)
        {
            for (int i = 0; i < strlen(exprsn); i++)
            {
                // '+' and '-' given together for equal precedence
                if (exprsn[i] == '+' || exprsn[i] == '-')
                {
                    printf("%c=%c%c%c\n", temp_var, exprsn[i - 1], exprsn[i], exprsn[i + 1]);
                    
                    exprsn[i - 1] = temp_var;
                    temp_var--;

                    for (int j = i; exprsn[j] != '\0'; j++)
                        exprsn[j] = exprsn[j + 2]; 
                    
                    flag = 1;
                    break;
                }
            }
        }
    }

    printf("%s\n", exprsn);
}

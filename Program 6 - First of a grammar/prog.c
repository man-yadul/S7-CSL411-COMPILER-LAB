#include <stdio.h>
#include <ctype.h>

void FIRST(char[], char);
void addToResultSet(char[], char);
int numOfProductions;
char productionSet[10][10];
void main()
{
    int i, j;
    char choice;
    char c, g;
    char result[20];
    printf("How many number of productions ? :");
    scanf(" %d", &numOfProductions);
    for (i = 0; i < numOfProductions; i++) // read production string eg: E=E+T
    {
        printf("Enter production Number %d : ", i + 1);
        scanf(" %s", productionSet[i]); // contains set of all productions
    }
    printf("FIRST OF : \n");
    for (i = 0; i < numOfProductions; i++)
    {
        c = productionSet[i][0];
        FIRST(result, c); // Compute FIRST; Get Answer in 'result' array
        if (productionSet[i][2] != '$')
        {
            printf("(%c) ={", c);
            for (j = 0; result[j] != '\0'; j++)
            {
                printf("%c ", result[j]);
            } // Display result
            printf("}\n");
        }
    }
}
/*
Function FIRST:
Compute the elements in FIRST(c) and write them in Result Array.
*/
void FIRST(char *Result, char c)
{
    int i, j, k;
    char subResult[20];
    int foundEpsilon;
    subResult[0] = '\0';
    Result[0] = '\0';
    // If X is terminal, FIRST(X) = {X}.
    if (!(isupper(c)))
    {
        addToResultSet(Result, c);
        return;
    }
    // If X is non terminal Read each production
    for (i = 0; i < numOfProductions; i++)
    {
        // Find production with X as LHS
        if (productionSet[i][0] == c)
        {
            // If X → ε is a production, then add ε to FIRST(X).
            if (productionSet[i][2] == '$')
                addToResultSet(Result, '$');
            // If X is a non-terminal, and X → Y1 Y2 … Yk is a production, then add a to FIRST(X) if for some i, a is in FIRST(Yi), and ε is in all of FIRST(Y1), …, FIRST(Yi-1).
            else
            {
                j = 2;
                while (productionSet[i][j] != '\0')
                {
                    foundEpsilon = 0;
                    FIRST(subResult, productionSet[i][j]);
                    for (k = 0; subResult[k] != '\0'; k++)
                        addToResultSet(Result, subResult[k]);
                    for (k = 0; subResult[k] != '\0'; k++)
                        if (subResult[k] == '$')
                        {
                            foundEpsilon = 1;
                            break;
                        }
                    // No ε found, no need to check next element
                    if (!foundEpsilon)
                        break;
                    j++;
                }
            }
        }
    }
    return;
}
// addToResultSet adds the computed element to result set. This code avoids multiple inclusion of elements
void addToResultSet(char Result[], char val)
{
    int k;
    for (k = 0; Result[k] != '\0'; k++)
        if (Result[k] == val)
            return;
    Result[k] = val;
    Result[k + 1] = '\0';
}

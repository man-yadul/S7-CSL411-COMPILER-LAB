#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count, n = 0;
// Stores the final result of the First Sets
char calc_first[10][100];

// Stores the production rules
char production[10][10];
char first[10];
int k;

void findfirst(char c, int q1, int q2)
{
    int j;

    // Terminal encountered
    if (isupper(c) == 0)
    {
        first[n++] = c;
    }

    for (j = 0; j < count; j++)
    {
        if (production[j][0] == c)
        {
            if (production[j][2] == '#')
            {
                if (production[q1][q2] == '\0')
                    first[n++] = '#';
                else if (production[q1][q2] != '\0' && (q1 != 0 || q2 != 0))
                {
                    // Recursion to calculate First of New non-terminal we encounter after epsilon
                    findfirst(production[q1][q2], q1, (q2 + 1));
                }
                else
                    first[n++] = '#';
            }
            else if (!isupper(production[j][2]))
            {
                first[n++] = production[j][2];
            }
            else
            {
                // Recursion to calculate First of new Non-Terminal we encounter at the beginning
                findfirst(production[j][2], j, 3);
            }
        }
    }
}

int main(int argc, char **argv)
{
    int jm = 0;
    int i, j, choice;
    char c, ch;

    printf("Enter no. of productions: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        printf("Enter production %d: ", i);
        scanf("%s", production[i]);
    }

    char done[count];
    int ptr = -1;

    // Initializing the calc_first array
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < 100; j++)
        {
            calc_first[i][j] = '!';
        }
    }
    int point1 = 0, point2, flag;

    for (k = 0; k < count; k++)
    {
        c = production[k][0];
        point2 = 0;
        flag = 0;

        // Checking if First of c has already been calculated
        for (int t = 0; t <= ptr; t++)
            if (c == done[t])
                flag = 1;

        if (flag == 1)
            continue;

        // Function call
        findfirst(c, 0, 0);
        ptr += 1;

        // Adding c to the calculated list
        done[ptr] = c;
        printf("\nFirst(%c) = {", c);
        calc_first[point1][point2++] = c;

        // Printing the First Sets of the grammar
        for (i = 0 + jm; i < n; i++)
        {
            int p = 0, chk = 0;

            for (p = 0; p < point2; p++)
            {
                if (first[i] == calc_first[point1][p])
                {
                    chk = 1;
                    break;
                }
            }

            if (chk == 0)
            {
                printf("%c, ", first[i]);
                calc_first[point1][point2++] = first[i];
            }
        }
        printf("}\n");
        jm = n;
        point1++;
    }
}

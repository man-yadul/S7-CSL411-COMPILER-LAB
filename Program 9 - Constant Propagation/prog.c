/*
Yadul Manoj
https://github.com/man-yadul

Constant propagation

The RHS of the expression can only have one operator and two operands, e.g. a=b+c
The input program MUST NOT HAVE ANY SPACES AND SEMICOLONS
The variable name CANNOT have more than one character, e.g. a=20 - valid, abc=20 - invalid

Sample input and output:
Enter no. of lines of the program: 5
Enter the program:
a=20
b=10
c=a+10
d=20-b
e=c*d
Line 3 after constant propagation: c=20+10
Result: 30
Line 4 after constant propagation: d=20-10
Result: 10
Line 5 after constant propagation: e=30*10
Result: 300
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// The values of number assignment statements are stored in this array
// If the statement is a=50, the number 50 will be stored at index 97 (ASCII value of 'a')
int values[150];

void main()
{
    int no_of_lines;
    char lines[20][20];

    printf("Enter no. of lines of the program: ");
    scanf("%d", &no_of_lines);
    printf("Enter the program:\n");
    for (int i = 0; i < no_of_lines; i++)
        scanf("%s", lines[i]);

    for (int i = 0; i < no_of_lines; i++)
    {
        // Check if line is a number assignment statement (eg:- a=2); flag is set to 1 if not
        int flag = 0;
        for (int j = 2; j < strlen(lines[i]); j++)
        {
            if (isalpha(lines[i][j]))
                flag = 1;
        }

        // Extract and store the number from the line
        // j = 2: RHS of the expression begins at index 2
        if (flag == 0)
        {
            int j;
            char temp[20];
            for (j = 2; j < strlen(lines[i]); j++)
                temp[j - 2] = lines[i][j];
            temp[j - 2] = '\0';

            int value = atoi(temp);
            values[lines[i][0]] = value;
        }
        // Arithmetic expression (eg:- b=a+c)
        else
        {
            int operand1, operand2;

            // Check if first operand is a variable or a constant
            if (isalpha(lines[i][2]))
                operand1 = values[lines[i][2]];
            // Extract the constant from the line
            else
            {
                int j;
                char temp[20];
                for (j = 2; isdigit(lines[i][j]); j++)
                    temp[j - 2] = lines[i][j];
                temp[j - 2] = '\0';
                operand1 = atoi(temp);
            }

            // Loop until the operator is found
            int j;
            char operator;
            for (j = 2; isalnum(lines[i][j]); j++)
                ;
            operator= lines[i][j];

            // Check if second operand is a variable or a constant
            if (isalpha(lines[i][j + 1]))
                operand2 = values[lines[i][j + 1]];
            // Extract the constant from the line
            else
            {
                int k, index = 0;
                char temp[20];
                for (k = j + 1; isdigit(lines[i][k]); k++)
                    temp[index++] = lines[i][k];
                temp[index++] = '\0';
                operand2 = atoi(temp);
            }

            printf("Line %d after constant propagation: %c=%d%c%d\n", i + 1, lines[i][0], operand1, operator, operand2);

            switch (operator)
            {
                case '+':
                    printf("Result: %d\n", operand1 + operand2);
                    values[lines[i][0]] = operand1 + operand2;
                    break;
                case '-':
                    printf("Result: %d\n", operand1 - operand2);
                    values[lines[i][0]] = operand1 - operand2;
                    break;
                case '*':
                    printf("Result: %d\n", operand1 * operand2);
                    values[lines[i][0]] = operand1 * operand2;
                    break;
                case '/':
                    printf("Result: %d\n", operand1 / operand2);
                    values[lines[i][0]] = operand1 / operand2;
                    break;
            }
        }
    }
}

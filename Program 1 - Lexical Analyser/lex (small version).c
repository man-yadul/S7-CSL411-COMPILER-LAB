// Yadul Manoj
// github.com/man-yadul

// Lexical Analyser (Small version)

// Supported keywords - int, long, float, double, void
// Supported operators - +, -, *, /, =
// Supported delimiters - (, ), {, }, [, ], ',', ;
// Single line and multi-line comments supported
// Input program is stored in file input.txt.

// Sample input: 

// void main()
// {
//     // afsafd
//     /* dvsdfsd
//     dsfdsffdds
//     hdhdfhdf*/
//     int a=15;
//     int b = 21;
//     float c = 3.1415;
//     double d = 2;
//     int a[4] = {1, 2, 3, 4};
// }

#include <stdio.h>
#include <string.h>

char line[100];

int is_operator(char c)
{
    switch (c)
    {
        case '+':   
        case '-':   
        case '*':   
        case '/':   
        case '=':   
            printf("%c - Operator\n", c);
            return 1;
    }

    return 0;
}

int is_delimiter(char c)
{
    switch (c)
    {
        case '{':
        case '}':
        case '(':
        case ')':
        case '[':
        case ']':
        case ',':
        case ';':
            printf("%c - Delimiter\n", c);
            return 1;
    }

    return 0;
}

int is_keyword(char token[])
{
    if (strcmp(token, "void") == 0 || strcmp(token, "main") == 0 ||
        strcmp(token, "int") == 0 || strcmp(token, "long") == 0 ||
        strcmp(token, "float") == 0 || strcmp(token, "double") == 0)
    { 
        return 1;
    }

    return 0;
}

void main()
{
    char c;
    FILE *f = fopen("input.txt", "r");

    while (fgets(line, sizeof(line), f))
    {
        // Single line commment '//', skip processing it
        for (int i = 0; i < strlen(line); i++)
        {
            if (line[i] == '/' && line[i + 1] == '/')
            {
                fgets(line, sizeof(line), f);
                break;
            }       
        }

        // Multi-line comment '/**/'
        for (int i = 0; i < strlen(line); i++)
        {
            int flag = 0;

            if (line[i] == '/' && line[i + 1] == '*')
            {
                // Skip all lines until '*/' has occured
                while (fgets(line, sizeof(line), f))
                {
                    for (int j = 0; j < strlen(line); j++)
                    {
                        if (line[j] == '*' && line[j + 1] == '/')
                            flag = 1;
                    }

                    if (flag)
                        break;
                }
            }

            if (flag)
            {
                fgets(line, sizeof(line), f);
                break;
            }
        }

        printf("\n%s\n", line);

        char token[100];
        int index = 0;
        strcpy(token, "");

        for (int i = 0; i < strlen(line); i++)
        {
            if (is_operator(line[i]) || is_delimiter(line[i]) || line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
            {
                // Check if the token is an identifier or a keyword
                if (strcmp(token, "") != 0)
                {
                    if (is_keyword(token))
                        printf("%s - Keyword\n", token);
                    else  
                        printf("%s - Identifier\n", token);

                    strcpy(token, "");
                    index = 0;
                }
            }
            else  
            {
                token[index++] = line[i];
                token[index] = '\0';
            }
        }
    }

    fclose(f);
}

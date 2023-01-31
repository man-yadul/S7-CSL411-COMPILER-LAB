/*
Yadul Manoj
github.com/man-yadul

Lexical Analyser

Supported keywords - int, long, float, double, void
Supported operators - +, +=, -, -=, *, *=, /, /=, =
Supported punctuators - ;
Supported separators - (, ), {, }

DO NOT ENTER THE INPUT PROGRAM WITHOUT SPACES BETWEEN EACH TOKEN (EXCEPT FOR THE
SEMICOLON). eg:- int a = 45; - Valid int a=45; - Invalid
Comment lines are NOT supported.

Input program is stored in the file input.txt.
Remove comment lines from the input file for the program to run properly.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
Refer the transition diagram in the folder before checking the logic of the
function. The function checks the validity of the operator that is passed. char
*token is a pointer to the string that holds the operator. char_ptr keeps track
of the current character that is checked. state holds the current state that
corresponds to the transition diagram. The function returns 1 if the operator is
valid, otherwise 0.
*/
int check_operator(char *token) {
  int char_ptr = 0;
  int state = 0;

  while (char_ptr <= strlen(token)) {
    switch (state) {
    case 0:
      if (token[char_ptr] == '+') {
        state = 1;
        char_ptr++;
      } else if (token[char_ptr] == '-') {
        state = 4;
        char_ptr++;
      } else if (token[char_ptr] == '*') {
        state = 7;
        char_ptr++;
      } else if (token[char_ptr] == '/') {
        state = 10;
        char_ptr++;
      } else if (token[char_ptr] == '=') {
        state = 13;
        char_ptr++;
      } else {
        return 0;
      }

      break;

    case 1:
      if (token[char_ptr] == '=') {
        state = 2;
        char_ptr++;
      } else if (token[char_ptr] == '\0') {
        state = 3;
      } else {
        return 0;
      }

      break;

    case 2:
      return 1;

      break;

    case 3:
      return 1;

      break;

    case 4:
      if (token[char_ptr] == '=') {
        state = 5;
        char_ptr++;
      } else if (token[char_ptr] == '\0') {
        state = 6;
      } else {
        return 0;
      }

      break;

    case 5:
      return 1;

      break;

    case 6:
      return 1;

      break;

    case 7:
      if (token[char_ptr] == '=') {
        state = 8;
        char_ptr++;
      } else if (token[char_ptr] == '\0') {
        state = 9;
      } else {
        return 0;
      }

      break;

    case 8:
      return 1;

      break;

    case 9:
      return 1;

      break;

    case 10:
      if (token[char_ptr] == '=') {
        state = 11;
        char_ptr++;
      } else if (token[char_ptr] == '\0') {
        state = 12;
      } else {
        return 0;
      }

      break;

    case 11:
      return 1;

      break;

    case 12:
      return 1;

      break;

    case 13:
      return 1;

      break;
    }
  }
}

/*
Refer the transition diagram in the folder before checking the logic of the
function. The function checks the validity of the number that is passed. char
*token is a pointer to the string that holds the number. char_ptr keeps track of
the current character that is checked. state holds the current state that
corresponds to the transition diagram. The function returns 1 if the number is
valid, otherwise 0.
*/
int check_number(char *token) {
  int char_ptr = 0;
  int state = 14;

  while (char_ptr <= strlen(token)) {
    switch (state) {
    case 14:
      if (isdigit(token[char_ptr]) != 0) {
        state = 15;
        char_ptr++;
      } else {
        return 0;
      }

      break;

    case 15:
      if (token[char_ptr] == '\0') {
        state = 16;
      } else if (isdigit(token[char_ptr]) != 0) {
        char_ptr++;
      } else {
        return 0;
      }

      break;

    case 16:
      return 1;

      break;
    }
  }
}

/*
Refer the transition diagram in the folder before checking the logic of the
function. The function checks the validity of the float number that is passed.
char *token is a pointer to the string that holds the float number.
char_ptr keeps track of the current character that is checked.
state holds the current state that corresponds to the transition diagram.
The function returns 1 if the float number is valid, otherwise 0.
*/
int check_float_number(char *token) {
  int char_ptr = 0;
  int state = 17;

  while (char_ptr <= strlen(token)) {
    switch (state) {
    case 17:
      if (isdigit(token[char_ptr]) != 0) {
        state = 18;
        char_ptr++;
      } else {
        return 0;
      }

      break;

    case 18:
      if (token[char_ptr] == '.') {
        state = 19;
        char_ptr++;
      } else if (isdigit(token[char_ptr]) != 0) {
        char_ptr++;
      } else {
        return 0;
      }

      break;

    case 19:
      if (isdigit(token[char_ptr]) != 0) {
        state = 20;
        char_ptr++;
      } else {
        return 0;
      }

      break;

    case 20:
      if (isdigit(token[char_ptr]) != 0) {
        char_ptr++;
      } else if (token[char_ptr] == '\0') {
        state = 21;
      } else {
        return 0;
      }

      break;

    case 21:
      return 1;

      break;
    }
  }
}

/*
Refer the transition diagram in the folder before checking the logic of the
function. The function checks the validity of the identifier that is passed.
char *token is a pointer to the string that holds the identifier.
char_ptr keeps track of the current character that is checked.
state holds the current state that corresponds to the transition diagram.
The function returns 1 if the identifier is valid, otherwise 0.
*/
int check_identifier(char *token) {
  int char_ptr = 0;
  int state = 22;

  while (char_ptr <= strlen(token)) {
    switch (state) {
    case 22:
      if (isalpha(token[char_ptr]) != 0 || token[char_ptr] == '_') {
        state = 23;
        char_ptr++;
      } else {
        return 0;
      }

      break;

    case 23:
      if (token[char_ptr] == '\0') {
        state = 24;
      } else if (token[char_ptr] != '\0' &&
                 (isalnum(token[char_ptr]) != 0 || token[char_ptr] == '_')) {
        char_ptr++;
      } else {
        return 0;
      }

      break;

    case 24:
      return 1;

      break;
    }
  }
}

void main() {
  char *token;
  char str[100];
  FILE *f = fopen("input.txt", "r");

  /*
  The below while loop reads each line of the file lex.txt.
  %[^\n] reads the entire line including the \n at the end of each line and it
  is stored in str. To prevent the \n character from getting stored in str, \n
  is included in the format string as %[^\n]\n. fscanf() returns 1 when EOF is
  reached.
  */
  while (fscanf(f, "%[^\n]\n", str) == 1) {
    printf("\nLine - %s\n", str);
    /*
    strtok() is used to split the string to multiple substrings with a space
    character as the delimiter. This is because the contents of the input file
    is in the form of tokens separated by spaces. eg:- int a = 45; DO NOT ENTER
    THE INPUT PROGRAM WITHOUT SPACES BETWEEN EACH TOKEN (EXCEPT FOR THE
    SEMICOLON). i.e., int a=45; - THIS WILL NOT GIVE A PROPER OUTPUT. (Semicolon
    MUST be entered without spacing)
    */
    token = strtok(str, " ");
    while (token != NULL) {
      if (strcmp(token, "void") == 0 || strcmp(token, "int") == 0 ||
          strcmp(token, "long") == 0 || strcmp(token, "float") == 0 ||
          strcmp(token, "double") == 0) {
        printf("%s - Keyword\n", token);
      } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' ||
                 token[0] == '/' || token[0] == '=') {
        if (check_operator(token) == 1)
          printf("%s : Operator\n", token);
        else
          printf("%s : Invalid operator\n", token);
      }
      /*
      token[strlen(token) - 1] == ')': Check if identifier contains a closing
      bracket (It's assumed '(' exists along with ')'; so it's not checked for
      existence). eg:- function definition - main()
      */
      else if (token[strlen(token) - 1] == ')') {
        // Replace '(' in the string to '\0' to mark the end of the string
        // without '()'
        token[strlen(token) - 2] = '\0';

        if (check_identifier(token) == 1)
          printf("%s : Identifier\n", token);
        else
          printf("%s : Invalid identifier\n", token);

        printf("( : Separator\n) : Separator\n");
      }
      // Semicolon is present at the end of an identifier or number
      else if (token[strlen(token) - 1] == ';') {
        // Replace ';' with '\0' to mark the end of the string without ';'
        token[strlen(token) - 1] = '\0';

        if (check_identifier(token) == 1)
          printf("%s : Identifier\n", token);

        if (check_number(token) == 1)
          printf("%s : Number\n", token);

        if (check_float_number(token) == 1)
          printf("%s : Float number\n", token);

        printf("; : Punctuation\n");
      }
      // Semicolon is NOT present at the end of an identifier or number
      else if (token[strlen(token) - 1] != ';' && isalnum(token[0]) != 0) {
        if (check_identifier(token) == 1)
          printf("%s : Identifier\n", token);

        if (check_number(token) == 1)
          printf("%s : Number\n", token);

        if (check_float_number(token) == 1)
          printf("%s : Float number\n", token);
      } else if (token[0] == '{' || token[0] == '}')
        printf("%s : Separator\n", token);
      else
        printf("%s : Invalid token\n", token);

      token = strtok(NULL, " ");
    }
  }
}

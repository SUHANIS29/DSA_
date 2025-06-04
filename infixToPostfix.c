#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to return precedence of operators
int prec(char c)
{
  if (c == '^')
    return 3;
  if (c == '/' || c == '*')
    return 2;
  if (c == '+' || c == '-')
    return 1;
  return -1;
}

// Function to perform infix to postfix conversion
void infixToPostfix(const char *exp)
{
  int len = strlen(exp);
  char result[len + 1]; // Resulting postfix expression
  char stack[len];      // Stack for operators
  int j = 0;            // Index for result
  int top = -1;         // Stack top

  for (int i = 0; i < len; i++)
  {
    char c = exp[i];

    // If the scanned character is an operand, add it to the output string.
    if (isalnum(c))
    {
      result[j++] = c;
    }
    // If the scanned character is '(', push it to the stack.
    else if (c == '(')
    {
      stack[++top] = c;
    }
    // If the scanned character is ')', pop from the stack to result until '(' is encountered.
    else if (c == ')')
    {
      while (top != -1 && stack[top] != '(')
      {
        result[j++] = stack[top--];
      }
      if (top != -1)
        top--; // Pop the '('
    }
    // If an operator is scanned
    else
    {
      while (top != -1 && prec(c) <= prec(stack[top]))
      {
        result[j++] = stack[top--];
      }
      stack[++top] = c;
    }
  }

  // Pop all remaining operators from the stack
  while (top != -1)
  {
    result[j++] = stack[top--];
  }

  result[j] = '\0'; // Null-terminate the resulting string
  printf("%s\n", result);
}

int main()
{
  char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
  infixToPostfix(exp);
  return 0;
}

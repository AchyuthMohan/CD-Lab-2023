#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int n, k = 0, row = 0, col = 0, top = 0;
  char opt[20][20][1], ter[20], ip[20], stack[20];
  printf("Enter the terminals: \n");
  scanf("%s", ter);
  n = strlen(ter);
  printf("Enter the precedence table: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Enter the value for %c %c: ", ter[i], ter[j]);
      scanf("%s", opt[i][j]);
    }
  }
  printf("\nOperator precedence table:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%c\t\t", ter[i]);
  }
  printf("\n");

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%c\t\t", opt[i][j][0]);
    }
    printf("\n");
  }

  stack[top] = '$';
  printf("Enter the input: ");
  scanf("%s", ip);
  while (k <= strlen(ip))
  {
    for (int i = 0; i < n; i++)
    {
      if (stack[top] == ter[i])
      {
        col = i;
      }
      if (ter[i] == ip[k])
      {
        row = i;
      }
    }

    if ((stack[top] == '$') &&( ip[k] == '$'))
    {
      printf("Accept..\n");
      return 0;
    }
    else if ((opt[col][row][0] == '<') || (opt[col][row][0] == '='))
    {
      stack[++top] = opt[col][row][0];
      stack[++top] = ip[k];
      k++;
      printf("SHIFT\n");
    }
    else
    {
      if (opt[col][row][0] == '>')
      {
        while (stack[top] != '<')
        {
          top--;
        }
        top = top - 1;
        printf("Reduce\n");
      }
      else
      {
        printf("reject\n");
        return 1;
      }
    }
    printf("%s\t\t", stack);
    for (int i = k; i < n; i++)
    {
      printf("%c", ip[i]);
    }
    printf("\t\t");
  }
}
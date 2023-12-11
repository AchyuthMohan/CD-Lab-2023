#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int n, top = 0, k = 0, row = 0, col = 0;
  char opt[10][10][1], ter[10], ip[10], stack[20];

  printf("Enter the number of terminals: \n");
  scanf("%d", &n);
  printf("Enter the terminals: \n");
  scanf("%s", ter);
  printf("Enter the operation precedence table: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Enter the precendence for %c %c: ", ter[i], ter[j]);
      scanf("%s", opt[i][j]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    printf("\t%c\t", ter[i]);
  }
  printf("\n");
  for (int i = 0; i < n; i++)
  {
    printf("\n%c", ter[i]);
    for (int j = 0; j < n; j++)
    {
      printf("\t%c", opt[i][j][0]);
    }
  }
  stack[top] = '$';
  printf("Enter the input string: \n");
  scanf("%s", ip);
  printf("\nSTACK\t\t\tINPUT\t\t\tACTION\n");
  printf("%s\t\t\t%s\t\t\t", stack, ip);
  k = 0;
  while (k <= strlen(ip))
  {
    for (int i = 0; i < n; i++)
    {
      if (stack[top] == ter[i])
      {
        col = i;
      }
      if (ip[k] == ter[i])
      {
        row = i;
      }
    }
    if (stack[top] == '$' && ip[k] == '$')
    {
      printf("String Accepted..\n");
      break;
    }
    else if ((opt[col][row][0] == '<') || (opt[col][row][0] == '='))
    {
      stack[++top] = opt[col][row][0];
      stack[++top] = ip[k];
      printf("shift %c\n", ip[k]);
      k++;
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
        printf("Reduce \n");
      }
      else
      {
        printf("String not accepted\n");
        break;
      }
    }
    printf("\n");
    for (int i = 0; i <= top; i++)
    {
      printf("%c", stack[i]);
    }
    printf("\t\t\t");
    for (int i = k; i < strlen(ip); i++)
    {
      printf("%c", ip[i]);
    }
    printf("\t\t\t");
  }
}

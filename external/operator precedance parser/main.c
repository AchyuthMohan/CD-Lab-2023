#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int n, top = 0, k = 0, col = 0, row = 0;
  char stack[20], ip[10], opt[10][10][1], ter[10];
  printf("Enter the number of terminals: \n");
  scanf("%d", &n);
  printf("Enter the terminals: \n");
  scanf("%s", ter);
  printf("Enter the precendence table: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Enter the value for %c %c: ", ter[i], ter[j]);
      scanf("%s", opt[i][j]);
    }
  }
  printf("Precendence table: \n");
  for (int i = 0; i < n; i++)
  {
    printf("\t%c", ter[i]);
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

  printf("Enter the input string: ");
  scanf("%s", ip);

  stack[top] = '$';
  printf("STACK\t\t\tINPUT\t\t\tACTION\n");
  printf("%s\t\t\t%s\t\t\t", stack, ip);
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
    if ((stack[top] == '$') && (ip[k] == '$'))
    {
      printf("String Accepted..\n");
      break;
    }
    else if ((opt[col][row][0] == '<') || (opt[col][row][0] == '='))
    {
      stack[++top] = opt[col][row][0];
      stack[++top] = ip[k];
      printf("Shifted: %c\n", ip[k]);
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
        printf("Reduce\n");
      }
      else
      {
        printf("String not accepted \n");
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
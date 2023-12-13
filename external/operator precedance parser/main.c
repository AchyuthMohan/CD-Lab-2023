#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int n, top = 0;
  char ter[20], opt[20][20][1], stack[20], ip[20];
  printf("Enter the number of terminals: \n");
  scanf("%d", &n);
  printf("Enter the terminals: ");
  scanf("%s", ter);
  printf("Enter the operator precedence table: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Enter the value for %c %c: ", ter[i], ter[j]);
      scanf("%s", opt[i][j]);
    }
  }

  for (int i = 0; i < n; i++)
  {
    printf("\t%c", ter[i]);
  }
  printf("\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("\t%c", opt[i][j][0]);
    }
    printf("\n");
  }
  stack[top] = '$';
  printf("Enter the input : \n");
  scanf("%s", ip);
  int k = 0, col = 0, row = 0;
  printf("\nstack\t\t\tinput\t\t\taction\n");
  printf("%s\t\t\t%s",stack,ip);
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
    if (stack[top] == '$' && ip[k] == '$')
    {
      printf("Accepted\n");
      break;
    }
    else if (opt[col][row][0] == '<' || opt[col][row][0] == '=')
    {
      stack[++top] = opt[col][row][0];
      stack[++top] = ip[k];
      k++;
      printf("\t\t\tShift\n");
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
        printf("\t\t\tReduce\n");
      }
      else
      {
        printf("\t\t\tError\n");
        break;
      }
    }
    printf("\n%s\t\t\t",stack);
    for(int i=k;i<=strlen(ip);i++){
      printf("%c",ip[i]);
    }
    printf("\t\t\t");
  }
}
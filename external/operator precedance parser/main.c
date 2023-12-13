#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char opt[20][20][1], stack[20], ter[20], input[20];
  int top = 0, col = 0, row = 0, n, k = 0;
  stack[top] = '$';
  printf("Enter the terminals: ");
  scanf("%s", ter);
  n = strlen(ter);
  printf("Enter the table values: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Enter the value for %c %c : ", ter[i], ter[j]);
      scanf("%s", opt[i][j]);
    }
  }

  printf("Operator precedence table: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("\t%c", opt[i][j][0]);
    }
    printf("\n");
  }

  printf("Enter the input string: \n");
  scanf("%s", input);
  printf("STACK\t\tINPUT\t\tACTION\n");
  printf("%s\t\t%s\t\t",stack,input);
  while (k <= strlen(input))
  {
    for(int i=0;i<n;i++){
      if(stack[top]==ter[i]){
        col=i;
      }
      if(ter[i]==input[k]){
        row=i;
      }
    }
    if(stack[top]=='$' && input[k]=='$'){
      printf("Accepted..\n");
      return 0;
    }
    else if((opt[col][row][0]=='<') || (opt[col][row][0]=='=')){
      stack[++top]=opt[col][row][0];
      stack[++top]=input[k];
      k++;
      printf("SHIFT\n");
    }
    else{
      if(opt[col][row][0]=='>'){
        while(stack[top]!='<'){
          top--;
        }
        top=top-1;
        printf("Reduce\n");
      }
      else{
        printf("Rejected..\n");
        exit(0);
      }
    }
    printf("%s\t\t",stack);
    for(int i=k;i<n;i++){
      printf("%c",input[i]);
    }
    printf("\t\t");
  }
}
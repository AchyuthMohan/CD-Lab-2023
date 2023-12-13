#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char opt[20][20][1], ter[20],ip[20],stack[20];
int n, i = 0,top=0;
int main()
{
  printf("Enter the terminals: ");
  scanf("%s", ter);
  n = strlen(ter);
  printf("Enter the precedence table: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Enter the precedence of %c %c: ", ter[i], ter[j]);
      scanf("%s", opt[i][j]);
    }
  }
  printf("Precedence Table: \n");
  for (int i = 0; i < n; i++)
  {
    printf("\t%c\t", ter[i]);
  }
  printf("\n");
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("\t%c\t",opt[i][j][0]);
    }
    printf("\n");
  }


  printf("Enter the input string: \n");
  scanf("%s",ip);
  int k=0;
  stack[top]='$';
  int row=0,col=0;
  while(k<=strlen(ip)){
    for(i=0;i<n;i++){
      if(stack[top]==ter[i]){
        col=i;
      }
      if(ter[i]==ip[k]){
        row=i;
      }
    }
    if(stack[top]=='$' && ip[k]=='$'){
      printf("Accepted\n");
      break;
    }
    else if(opt[col][row][0]=='<' || opt[col][row][0]=='='){
      stack[++top]=opt[col][row][0];
      stack[++top]=ip[k];
      k++;
      printf("shift\n");
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
        printf("Not Accepted..\n");
        break;
      }
    }
    printf("%s\t\t",stack);
    for(i=k;i<n;i++){
      printf("%c",ip[i]);
    }
    printf("\t\t");
  }
}
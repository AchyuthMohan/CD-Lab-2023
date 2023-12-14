#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int z,i=0,j=0,n;
char stack[20],input[20],shift[20],reduce[20];

void check(){
    for(z=0;z<n;z++){
        if(stack[z]=='i' && stack[z+1]=='d'){
            stack[z]='E';
            stack[z+1]='\0';
            printf("$%s\t\t%s\t\t%s\n",stack,input,reduce);
            j++;
        }
    }
    for(z=0;z<n;z++){
        if(stack[z]=='E' && stack[z+1]=='+' && stack[z+2]=='E'){
            stack[z]='E';
            stack[z+1]='\0';
            stack[z+2]='\0';
            printf("$%s\t\t%s\t\t%s\n",stack,input,reduce);
            i--;
        }
    }
    for(z=0;z<n;z++){
        if(stack[z]=='E' && stack[z+1]=='*' && stack[z+2]=='E'){
            stack[z]='E';
            stack[z+1]='\0';
            stack[z+2]='\0';
            printf("$%s\t\t%s\t\t%s\n",stack,input,reduce);
            i--;
        }
    }
    for(z=0;z<n;z++){
        if(stack[z]=='E' && stack[z+1]=='/' && stack[z+2]=='E'){
            stack[z]='E';
            stack[z+1]='\0';
            stack[z+2]='\0';
            printf("$%s\t\t%s\t\t%s\n",stack,input,reduce);
            i--;
        }
    }
}
int main(){
    strcpy(shift,"SHIFT");
    strcpy(reduce,"REDUCE");
    printf("Grammar: E->E+E | E*E | E/E | id\n");
    printf("Enter the string: ");
    scanf("%s",input);
    n=strlen(input);
    for(i=0,j=0;j<n;i++,j++){
        if(input[j]=='i' && input[j+1]=='d'){
            stack[i]=input[j];
            stack[i+1]=input[j+1];
            stack[i+2]='\0';
            input[j]=input[j+1]=' ';
            printf("$%s\t\t%s\t\t%s\n",stack,input,shift);
            check();
        }
        else{
            stack[i]=input[j];
            stack[i+1]='\0';
            input[j]=' ';
            printf("$%s\t\t%s\t\t%s\n",stack,input,shift);
            check();
        }
    }
}
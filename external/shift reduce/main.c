#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[30],ip[30],act[20],ac[20];
int i=0,j=0,z=0,n;
void check(){
    for(z=0;z<n;z++){
        if(stack[z]=='i' && stack[z+1]=='d'){
            stack[z]='E';
            stack[z+1]='\0';
            printf("%s\t\t%s\t\t%s\n",stack,ip,ac);
            j++;
        }
    }
    for(z=0;z<n;z++){
        if(stack[z]=='E' && stack[z+1]=='+' && stack[z+2]=='E'){
            stack[z]='E';
            stack[z+1]='\0';
            stack[z+2]='\0';
            printf("%s\t\t%s\t\t%s\n",stack,ip,ac);
            i=i-1;
        }
    }
    for(z=0;z<n;z++){
        if(stack[z]=='E' && stack[z+1]=='*' && stack[z+2]=='E'){
            stack[z]='E';
            stack[z+1]='\0';
            stack[z+2]='\0';
            printf("%s\t\t%s\t\t%s\n",stack,ip,ac);
            i=i-1;
        }
    }
    for(z=0;z<n;z++){
        if(stack[z]=='(' && stack[z+1]=='E' && stack[z+2]==')'){
            stack[z]='E';
            stack[z+1]='\0';
            stack[z+2]='\0';
            printf("%s\t\t%s\t\t%s\n",stack,ip,ac);
            i=i-1;
        }
    }
}
int main(){
    printf("Grammar: \n E->E+E\nE->E*E\nE->(E)\nE->id\n");
    printf("enter the string input: ");
    scanf("%s",ip);
    n=strlen(ip);
    strcpy(act,"SHIFT symbol");
    strcpy(ac,"REDUCE E");
    printf("STACK\t\tINPUT\t\tACTION\n");
    for(i=0,j=0;j<n;i++,j++){
        if(ip[j]=='i' && ip[j+1]=='d'){
            stack[i]=ip[j];
            stack[i+1]=ip[j+1];
            stack[i+2]='\0';
            ip[i]=ip[i+1]=' ';
            printf("%s\t\t%s\t\t%s\n",stack,ip,act);
            check();
        }
        else{
            stack[i]=ip[j];
            ip[j]=' ';
            stack[i+1]='\0';
            printf("%s\t\t%s\t\t%s\n",stack,ip,act);
            check();
        }
    }
}
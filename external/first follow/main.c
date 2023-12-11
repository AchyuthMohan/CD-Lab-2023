#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define max 20

char f[max],a[max][max];
int m=0,n;

void first(char ch){
    if(islower(ch)){
        f[m++]=ch;
    }
    for(int i=0;i<n;i++){
        if(a[i][0]==ch){
            if(islower(a[i][2])){
                f[m++]=a[i][2];
            }
            else{
                first(a[i][2]);
            }
        }
    }
}

void follow(char ch){
    if(ch==a[0][0]){
        f[m++]='$';
    }
    for(int i=0;i<n;i++){
        for(int j=2;j<strlen(a[i]);j++){
            if(a[i][j]==ch){
                if(a[i][j+1]!='\0'){
                    first(a[i][j+1]);
                }
                else if(a[i][j+1]=='\0' && a[i][0]!=ch){
                    follow(a[i][0]);
                }
            }
        }
    }
}

int main(){
    printf("Enter the number of productions: \n");
    scanf("%d",&n);
    printf("Enter the grammar: \n");
    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    while(1){
        printf("Enter the symbol whose first and follow has to be calculated: \n");
        char ch;
        scanf("%c",&ch);
        first(ch);
        printf("First(%c)= { %c ,",ch,ch );
        for(int i=0;i<m;i++){
            printf("%c, ",f[i]);
        }
        printf("}");
    }
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
int n,i;
FILE *fp;
char states[max][max],result[max][max],copy[3],state[3],state1[3],state2[3],input[3];
void addState(char a[3],int q){
    strcpy(result[q],a);
}

void display(int n){
   int k=0;
   printf("Epsilon closure of %s = {",copy);
   while(k<n){
    printf("%s,",result[k]);
    k++;
   }
   printf("}");
}
int main(){
    fp=fopen("input.dat","r");
    printf("Enter the number of states: \n");
    scanf("%d",&n);
    printf("Enter the states: \n");
    for(int k=0;k<n;k++){
        scanf("%s",states[k]);
    }
    int end;

    for(int k=0;k<n;k++){
        i=0;
        strcpy(state,states[k]);
        strcpy(copy,state);
        addState(state,i++);
        while(1){
            end=fscanf(fp,"%s%s%s",state1,input,state2);
            if(end==EOF){
                break;
            }
            if(strcmp(state1,state)==0){
                if(strcmp(input,"e")==0){
                    strcpy(state,state2);
                    addState(state2,i++);
                }
            }
        }
        display(i);
    }

}
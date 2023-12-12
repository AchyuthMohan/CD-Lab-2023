#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char ip[20];
char *cursor;

int E(),Edash(),T(),Tdash(),F();

int main(){
    printf("Grammar: \n E->E+T|T\nT->T*F|F\nF->(E) | i\n");
    printf("Enter the expression: ");
    scanf("%s",ip);
    cursor=ip;
    if(E() && *cursor=='\0'){
        printf("Accepted\n");
        return 0;
    }
    else{
        printf("Rejected\n");
        exit(1);
    }

}


int E(){
    if(T()){
        if(Edash()){
            printf("\nE->TE'");
            return 1;
        }
        return 0;
    }
    return 0;
}
int Edash(){
    if(*cursor=='+'){
        cursor++;
        if(T()){
            if(Edash()){
                printf("\nE'->+TE'");
                return 1;
            }
            return 0;
        }
        return 0;
    }
    printf("\nE'->e");
    return 1;
}
int T(){
    if(F()){
        if(Tdash()){
            printf("\nT->FT'");
            return 1;
        }
        return 0;
    }
    return 0;
}
int Tdash(){
    if(*cursor=='*'){
        cursor++;
        if(F()){
            if(Tdash()){
                printf("\nT'->*FT'");
                return 1;
            }
            return 0;
        }
        return 0;
    }
    printf("\nT'->e");
    return 1;
}
int F(){
    if(*cursor=='('){
        cursor++;
        if(E()){
            if(*cursor==')'){
                printf("\nF->(E)");
                cursor++;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    else if(*cursor=='i'){
        printf("\nF->i");
        cursor++;
        return 1;
    }
    return 0;
}
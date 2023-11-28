%{
    #include "y.tab.h"
    int isPalindrome(char temp[]){
        int i=0;
        int j=strlen(temp)-1;
        while(i<j){
            if(temp[i]!=temp[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
%}
%%
%%
int yywrap(){
    return 1;
}
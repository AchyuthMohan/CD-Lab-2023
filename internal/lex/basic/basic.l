digit [0-9]+
string [a-zA-Z]+

%%
{digit} printf("digit");
{string} printf("String");
%%
int main(){
    yylex();
}
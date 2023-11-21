substring [a-zA-Z]*[^aA][^cC][^hH][^yY][a-zA-Z]*

%%
{substring} printf("%s",yytext);
%%
int main(){
    yylex();
}
%{
    #include "y.tab.h"
    extern int yylval;
%}
%%
[a-zA-Z] {return LET;}
[0-9] {return LET;}
%%
int yywrap(){
    return 1;
}
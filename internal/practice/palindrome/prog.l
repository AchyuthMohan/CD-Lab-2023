%{
    #include "y.tab.h"
%}

%%
[a-zA-Z0-9]* {return LET;}
%%
int yywrap(){
    return 1;
}
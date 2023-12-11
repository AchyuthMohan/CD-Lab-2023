%{
    #include "y.tab.h"
%}

%%
[a-z]* {return LET;}
[_]* {return LET;}
[0-9]* {return DIG;}
[\n] {return 0;}
%%

int yywrap(){
    return 1;
}
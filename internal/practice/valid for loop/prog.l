%{
    #include "y.tab.h"
%}

%%
for {return FOR;}
[a-z] {return LET; }
[0-9]   {return DIG;}
%%

int yywrap(){
    return 1;
}
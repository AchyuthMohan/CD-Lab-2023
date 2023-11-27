%{
#include "y.tab.h"    
%}

%%
[a-z] {return LET; }
[a-z]* {return CONT;}

%%

int yywrap(){
    return 1;
}
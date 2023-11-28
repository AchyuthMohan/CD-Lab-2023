%{
#include "y.tab.h"
%}

%%

0 {return ZERO;}
1 {return ONE; }
[0|1] {return ANY ;}
%%
int yywrap(){
    return 1;
}
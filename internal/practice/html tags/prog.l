%{
#include "y.tab.h"    
%}

%%
"<html>" | "<head>"| "<body>" | "<p>"  {return OPEN;}
"</html>" | "</head>"| "</body>" | "</p>" {return CLOSE;}
[a-z]* {return CONTENT ;}
%%

int yywrap() {
    return 1;
}

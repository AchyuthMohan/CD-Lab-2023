%{
#include "y.tab.h"    
%}

%%
[<]html[>]   { return OPEN_HTML; }
[<]body[>]   { return OPEN_BODY; }
[<]head[>]   { return OPEN_HEAD; }
[<]p[>]      { return OPEN_P; }
[<]/html[>]  { return CLOSE_HTML; }
[<]/body[>]  { return CLOSE_BODY; }
[<]/head[>]  { return CLOSE_HEAD; }
[<]/p[>]     { return CLOSE_P; }
[a-z]+       {  return CONTENT; }
[ \t\n]+     ;  // Ignore whitespace (changed from [ \t\n])
.            { return yytext[0]; }  // Return unrecognized characters

%%

int yywrap() {
    return 1;
}

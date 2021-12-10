%{  
 #include "y.tab.h"  
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
%}  
%%  
[a-zA-Z] { return LETTER ;}  
[0-9] { return DIGIT ; }  
[\n] { return NL ;}  
[_] { return UND; }  
. { return yytext[0]; }  
%%
%{  
    /* Definition section*/  
    #include "y.tab.h"     
    #include<string.h>     
    extern yylval;  
%}  

%%  
sqrt { return SQRT;} 
strlen {return STRLEN;} 
pow {return POW;}  
[0-9]+ {
    yylval=atoi(yytext);   
    return NUMBER;  
}  
[a-zA-Z]+    { return string; }  
[ \t]+         ;  /For skipping whitespaces/  

\n            { return 0; }  
.            { return yytext[0];}  
%%
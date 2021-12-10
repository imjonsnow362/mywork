%{  
    /* Definition section */  
    #include <stdio.h>
%}  

%token DIGIT LETTER NL UND  
%%  
stmt : variable NL { printf("Valid Identifiers\n");   
    return 0;  
};
  
variable : LETTER alphanumeric; alphanumeric: LETTER alphanumeric  
 | DIGIT alphanumeric  
 | UND alphanumeric  
 | LETTER  
 | DIGIT  
 | UND  
 ;  
%%  

int yyerror(char *msg)  {  
    printf("Invalid Expression\n"); 
    return 0; 
    } 
int main ()  {  
    printf("Enter the variable name\n"); 
    yyparse();  
} 

int yywrap(){ 
    return(1);  
}
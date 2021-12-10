%{  
#include <math.h>  
#include<string.h>
#include <stdio.h>
%}
  

%token SQRT NUMBER STRLEN string CEIL POW FLOOR ABS  

%%  
s : sq {printf("Square of number= %d\n", $1); return 0;}   | 
    str{printf("length of string = %d\n",$1); return 0;}   | 
    pow{printf("Power of number = %d\n",$1); return 0;} 
sq : SQRT '(' NUMBER ')' {$$=sqrt($3);} 
str: STRLEN '('string')' {$$=strlen($3);} 
pow: POW '(' NUMBER ',' NUMBER')' {$$=pow($3,$5);} ;  
%%  

int main() {  
	printf("Enter the expression\n"); 
	yyparse();  
}  

/* For printing error messages */ 
int yyerror(char* s) {   
	printf("\nExpression is invalid\n");  
}  

int yywrap(){  
	return 1;  
}
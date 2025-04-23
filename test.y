%{
#include <stdio.h>
#include <stdlib.h>
int flag = 0;
int yylex();
void yyerror(const char *s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'


%%
ArithmeticExpression: E { 
    printf("\nResult = %d\n", $1); 
    return 0;
};

E: E '+' E { $$ = $1 + $3; }
 | E '-' E { $$ = $1 - $3; }
 | E '*' E { $$ = $1 * $3; }
 | E '/' E { $$ = $1 / $3; }
 | E '%' E { $$ = $1 % $3; }
 | '(' E ')' { $$ = $2; }
 | NUMBER { $$ = $1; }
;
%%


int main()
{
    printf("Enter any arithmetic expression: ");
    yyparse();
    
    if (flag == 0)
        printf("\nEntered arithmetic expression is Valid\n\n");
    return 0;
}

void yyerror(const char *s)
{
    printf("\nEntered arithmetic expression is Invalid\n\n");
    flag = 1;
}
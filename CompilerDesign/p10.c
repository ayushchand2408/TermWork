%option noyywrap

%{
    #include<stdio.h>
%}

{Keyword} "int"|"float"|"char"|"string"|"if"|"else"|"switch"|"return"
{id} [a-zA-Z][a-zA-Z0-9_]* 
{operator} "+"|"-"|"*"|"/"|"%"
{speartor} ","|";"|"("|")"|"{"|"}"
{costant} [0-9]+(\.[0-9]*)?

%%
{Keyword} {prints("%s is a keyword",yytext);}
{id} {prints("%s is a id",yytext);}
{operator} {prints("%s is a operator",yytext);}
{speartor} {prints("%s is a speartor",yytext);}
{costant} {prints("%s is a costant",yytext);}



%%
int main(){
    printf("enter the string : ");

    yylex();
}

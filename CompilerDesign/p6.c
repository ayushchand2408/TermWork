%option noyywrap;
%{
    #include<stdio.h>    
    int character =0;
    int words=0;
    int spaces=0;
%}

%%
[a-zA-Z0-9]+ {character+=yyleng, word++;}
[\t\n]+ {character += yyleng , spaces += yyleng;}
. {character++;}
%%


int main(){
    FILE *in = fopen("input.text","r");
    if(!in){
        return 1;
    }
    yyin = in;
    yylex();
    printf("totla number of character %d\n:",character);
    printf("totla number of words %d\n:",words);
    printf("totla number of spaces %d\n:",spaces);


}
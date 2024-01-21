#include<stdio.h> 
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include "main.c"
int main() { 
    char s[200] = {};
    list L;
    init(&L);

    printf("                                  BINARY CALCULATOR          \n");
    printf("---------------------------------------------------------------------------------\n");
    printf(">>> ");

    while(1) {

        init(&L);

        gets(s);            //Accepts the expression to be evaluated
        infix_eval(s);      //Evaluates the expression and displays the answer
         
    }
    return 0;
}
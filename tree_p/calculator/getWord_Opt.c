#include "getWord_Opt.h"
#include <stdlib.h> 
int isS_OPT(char input)
{
    switch(input)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '\0':
        return 1;
    }
    return 0;
}
 int initopt(char inopt,Oprator * inOPT)
{
    int prio;
    switch (inopt) 
    {
    case '\0':
        prio = NONE;
        break;
    case '-':
    case '+':
        prio = 1;
        break;
    case '*':
    case '/':
        prio = 2;
    }
    inOPT->optchar = inopt;
    inOPT->priority = prio;
    return 1; 
}

Expr *  initW_O(char * str) // generate the W_O Type
{
    Expr * retINIT = (Expr *)malloc(sizeof(Expr));
    char * pool = (char *)malloc(sizeof(char)*MAX);
    strcpy(pool,str);
    retINIT->string = pool;
    retINIT->ptr=pool;
    return retINIT;
}
int  getW_O(Expr * expr,word_opt * retW_O )  // get a W_O struct
{
    char word[MAX];
    Oprator opt;

    if(*(expr->ptr)== '\0')
        return 0;
    char * cptr = word;
    do
    {
        *cptr = *(expr->ptr);
        cptr++;
        (expr->ptr)++;
    }while( !(isS_OPT( *(expr->ptr))) );
    *cptr = *(expr->ptr); // copy special oprator
                          //incluce '\0'
    if(*(expr->ptr) == '\0')
        initopt('\0',&opt);
    else
    {
        initopt(*(expr->ptr),&opt);
        expr->ptr++; //for the next opration
    }

    retW_O = (word_opt *)malloc(sizeof(word_opt));
    retW_O->value = stoi(word);
    retW_O->opt = opt;
    return 1;
}

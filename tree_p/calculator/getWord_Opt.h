#include <stdio.h>
#include <string.h>
#define NONE 0
#define MAX 50
// SPOT -+*/  '\0'
typedef struct Oprator{
    char optchar;
    int priority;
}Oprator;
typedef struct W_O{
    //char words[MAX];
    int value;
    Oprator opt;
}word_opt;

typedef struct Expr{
    const char * string;
    char * ptr;
}Expr;
Expr *   initW_O(char * str); // generate the W_O Type
int  getW_O(Expr * expr,word_opt * retW_O );  // get a W_O struct

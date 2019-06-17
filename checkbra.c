// The stack simplefied the process
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int is_in_left(char ch);
int match(char ch1,char ch2);
int main (void)
{
    SqStack stack;
    InitStack(&stack);// create a stack
    char gch;
    char ch = 0; // tmp char variable;
    printf("Please enter a set of bra..:\n");
    while ((gch = getchar()) != '\n') 
    {

        if (is_in_left(gch))
        {
            if(push(&stack,gch) !=  OK)
                perror("push");
        }
        else // then gch in rightset
        {
            if(pop(&stack,&ch) != OK)
            {
                printf("This is not a good match!\n");
                return 0;
            }
            if (!match(gch,ch))
            {
                printf("This is not a good match!!!\n");
                return 0;
            }
        }
    }
    if (StackEmpty(stack))// stack is empty??
        printf("This is a good match!!!\n");
    else 
        printf("This is not a good match!!!\n");
    return 0;
}
int is_in_left(char ch)
{
    switch (ch)
    {
        case '{':
            return 1;
        case '[':
            return 1;
        case '<':
            return 1;
        case '(':
            return 1;
        default:
            return 0;

    }
}
int match(char ch1,char ch2)
{
    // make sure the ch1 and ch2 is matched
    if ( (ch1 == '}'&& ch2 == '{') \
         || (ch1 == '{'&& ch2 == '}'))
        return 1;
    if ( (ch1 == ')'&& ch2 == '(') \
         || (ch1 == '('&& ch2 == ')'))
        return 1;
    if ( (ch1 == ']'&& ch2 == '[') \
         || (ch1 == '['&& ch2 == ']'))
        return 1;
    if ( (ch1 == '>'&& ch2 == '<') \
         || (ch1 == '<'&& ch2 == '>'))
        return 1;
    return 0;
    }

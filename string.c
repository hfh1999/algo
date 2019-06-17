#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int strassign(ptrstr string,char * instr)
{
    // if the Str is not NULL!!!!
    char * cha=instr;
    if (string->ch)
        free(string->ch);
    int len = 0;
    while (*cha != '\0')
    {
        len++;
        cha++;
    }
    if(len == 0 )
    {
        string->ch = NULL;
        string->length = 0;
        return 1;
    }
    else
    {
        string->ch = (char * )malloc( (len+1)*sizeof(char) );
        if(string->ch == NULL)
            return 0;
        for (cha = string->ch;*instr != '\0';cha++,instr++)
            *cha=*instr;
        *(++cha)='\0';
        string->length=len;
    }
        
    return 1;
}
int strlength(Str string)
{
    return string.length;
}
int strcompare(Str s1,Str s2)
{

}
int strcat(ptrstr outstr,Str s1,Str s2);
int substring(ptrstr substr,Str s1,Str s2);
int clearstr(ptrstr instr);

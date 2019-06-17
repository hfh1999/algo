typedef struct str{
    char * ch;
    int length;
}Str,* ptrstr;
int strassign(ptrstr string,char * instr);
int strlength(Str string);
int strcompare(Str s1,Str s2);
int strcat(ptrstr outstr,Str s1,Str s2);
int substring(ptrstr substr,Str s1,Str s2);
int clearstr(ptrstr instr);

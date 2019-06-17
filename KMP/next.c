#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define RESIZE 20
int main(void)
{
    char * tstring = (char *)malloc(SIZE * sizeof(char));
    int size = SIZE;
    char ch;
    int i = 0;
   while ((ch = getchar()) != '\n') 
   {
       tstring[i] = ch;
       i++;
       if (i == size)// there no enough room
       {
           size += RESIZE;
            tstring =(char *) realloc(tstring ,size);
       }
   }
   printf("there are %d characters!!!\n",i);

     
}

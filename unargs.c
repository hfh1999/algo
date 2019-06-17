#include <stdio.h>
void htry(int a,...);
int main (void)
{
    htry(1,2,3,4);
    return 0;
}
void htry(int a,...)
{
    int * ptr=&a;
    int i;
    for(i = 0;i<4;i++)
    {
        printf("%d\n",*ptr++);
    }
}

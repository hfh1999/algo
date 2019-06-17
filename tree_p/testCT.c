#include "include/tree.h"
int main (void)
{
    BTnode * test =NULL; 
    int num;
    printf("Please enter a level number:\n");
    scanf("%d",&num);
    if((test = createTree(num)) == NULL)
        printf("failed!!!\n");
    showtree(test);
        return 0;
}

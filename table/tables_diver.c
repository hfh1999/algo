#include "tables_nodes.h"
int main(void)
{
    float *tarry[4];
    int i,j;
    for ( i = 0;i<4 ;i++)
    {
        tarry[i] = (float *)malloc\
                   (sizeof(float)*5);
    }
    for( i = 0;i < 4;i++)
        for(j = 0 ;j < 5;j++)
            tarry[i][j]=1;
    tables tt;
    if(!(tcreate(&tt,4,5)))
    {
        printf("error!!! tcreate.");
        exit(1);
    }
    if(!(arrytot(&tt,tarry,4,5)))
    {
        printf("error!!! arrytot.");
        exit(1);
    }
    printf("Succsess!!!\n");
    return 0;
}

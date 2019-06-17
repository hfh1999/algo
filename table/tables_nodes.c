#include "tables_nodes.h"
int tcreate(ptrtables table,int rows,int cols );
int arrytot(ptrtables table,float ** arry,\
            int rows,int cols );
// some problem!!!
int tcreate(ptrtables table,int rows,int cols )
{
    //table=(ptrtables)malloc(sizeof(tables));// haha!!!
    table->Rows = rows;
    table->Cols=cols;
    table->rowhead=(ptrnode)malloc(sizeof(node)*cols);
    table->colhead=(ptrnode)malloc(sizeof(node)*rows);
    if(table->rowhead==NULL||table->colhead==NULL)
        return 0;
    return 1;
}

//scan the arry and transfer to tables
int arrytot(ptrtables table,float ** arry,\
            int rows,int cols )
{
    int i,j;
    int num = 0;
    ptrnode ptrrows[cols];
    //do a useful ptr arry
    for (i = 0;i<cols;i++)
        ptrrows[i] = table->rowhead + i;
    for (i=0;i<rows;i++)
    {
        ptrnode ptrcols = table->colhead + i;
        for(j=0;j<cols;j++)
        {
            if(arry[i][j] != 0)
            {
                ptrcols->right=(ptrnode)malloc(sizeof(node));
                ptrcols=ptrcols->right;
                // init the ptr's struct
                ptrcols->data = arry[i][j];
                ptrcols->Row = i;
                ptrcols->Col = j;
                ptrrows[j]->down=ptrcols;
                ptrrows[j]=ptrrows[j]->down;
                num++;
            }
        }
    }
    table->num=num;
    return 1;
}

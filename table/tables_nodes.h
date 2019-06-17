// a ADT to simplefy the arry storation;
#include <stdio.h>
#include <stdlib.h>
typedef struct node node,* ptrnode;
 struct node{
    int Row;
    int Col;
    float data;
    ptrnode down;
    ptrnode right;
};
typedef struct tables{
    int Rows;
    int Cols;
    int num;
    ptrnode rowhead;
    ptrnode colhead;
}tables,* ptrtables;
int tcreate(ptrtables table,int rows,int cols );
int arrytot(ptrtables table,float ** arry,int rows,int cols );


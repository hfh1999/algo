#include <stdio.h>
#include <stdlib.h>
typedef struct BTnode{
     BTnode * lchild;
     BTnode * rchild;
     char data;
} BTnode,* Ptrnode;
int comp(Ptrnode ptr);
int opt(int a, int b,char c);
int main (void)
{

}
int comp(Ptrnode ptr)
{
    int A,B;
    if (ptr != NULL) // if the tree is not empty
    {
        if (ptr->lchild != NULL && ptr->rchild != NULL)
        {
            A = comp(ptr->lchild);
            B = comp(ptr->rchild);
            return opt(A,B,ptr->data); // caculate the A-date-B 
        }
        else
            return ptr->data - '0'; // if the node is a date then return ;
    }
    else 
        return 0;
}
int opt(int a, int b,char c)
{
    switch (c)
    {
        case '+':
            return a + b ;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    };
}

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
int main (void)
{
    return 0;
}
void count(BTnode * tree)
{
    Queue myqueue;
    Qnode pool;
    BTnode * nptr;
    initQ(&myqueue);// init my queue
    // bilud my queue 
    if(tree == NULL)
        return;

    pool.level=1;
    pool.root=tree;
    int maxwide = 0;
    int count = 0;
    enqueue(&myqueue,pool); //make the root enter the queue
    while(emptyQ(&myqueue)) // the queue is not empty
    {
        dequeue(&myqueue,&pool);
        count ++;
        nptr = pool.root;        //dequeue
        if(nptr->leftchild != NULL)
        {
            pool.root = nptr->leftchild;
            if(emptyQ(&myqueue) || \
                myqueue.front->level != myqueue.front->ptr->level ) //get the new level
            {
                pool.level = myqueue.front->level + 1;
                count = 0; // reset the num of current level
            }
            enqueue(&myqueue,pool);
            maxwide = (maxwide > count)? maxwide:count; // refresh the max width
        }
        
    }
    printf("wide: %d",maxwide);
    return;
}

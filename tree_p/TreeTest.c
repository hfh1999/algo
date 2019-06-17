#include "include/tree.h"
//init fetch's BTnode
#define DATAINIT(COUNT) fetch->data = COUNT;\
                        fetch->leftchild = NULL; \
                        fetch->rightchild = NULL
//full the qnode
#define QNODEINIT(LEVEL) qnode.level=LEVEL;\
                    qnode.root=fetch;\
                    qnode.ptr=NULL//some bugs here
// some trouble : the last level can be  olny create one node
typedef struct Qnode{
    BTnode * root;
    int level;
    struct Qnode * ptr;
} Qnode;
typedef struct Queue{
    Qnode * front;
    Qnode * rear;
    Qnode * thisQ;
}Queue;
int initQ (Queue * queue);
int enqueue (Queue * queue,Qnode qnode );
int dequeue (Queue * queue,Qnode * qnode);
int emptyQ(Queue * queue);
BTnode * createTree(int level);
void showtree(BTnode * root);

BTnode * createTree(int level)
{
    BTnode * fetch;
    BTnode * tree;
    Queue myqueue;
    Qnode  qnode;
    int curlevel = 1;
    int count = 0;
    initQ(&myqueue);
    

    fetch = (BTnode *) malloc (sizeof(BTnode));
    tree = fetch; //return value
    DATAINIT(count);
    QNODEINIT(curlevel);
    enqueue(&myqueue,qnode);

    while (curlevel <= level )
    {
        BTnode * tmp;
        dequeue(&myqueue,&qnode);
        // curlevel
        curlevel = qnode.level+1;
        tmp =qnode.root;

        fetch = (BTnode *)malloc(sizeof(BTnode));
        tmp ->leftchild = fetch;
        //init fetch's BTnode
        DATAINIT(++count);
        //full the qnode
        QNODEINIT(curlevel);
        enqueue(&myqueue,qnode);

        fetch = (BTnode *)malloc(sizeof(BTnode));
        tmp->rightchild = fetch;
        DATAINIT(++count);
        QNODEINIT( curlevel );
        enqueue(&myqueue,qnode);
    }
    return tree;
}

void showtree(BTnode * root)// show tree as visable mod
{
    Qnode fetch;
    Queue myqueue;
    int level;

    initQ(&myqueue);

    fetch.root = root;
    fetch.level = 1; 
    if(!enqueue(&myqueue,fetch))
        printf("error");
    while(!emptyQ(&myqueue))
    {
        static int oldlevel = 1;

        dequeue(&myqueue,&fetch);
        level = fetch.level;
        BTnode * tmp = fetch.root;

        if(oldlevel != level)
            printf("\n");
        //some pro
        printf("%d   ",tmp->data);
        
        if(tmp->leftchild != NULL)
        {
            fetch.level = level + 1;
            fetch.root = tmp->leftchild;
            enqueue(&myqueue,fetch);
        }
        if (tmp->rightchild != NULL)
        {
            fetch.level = level + 1;
            fetch.root = tmp->rightchild;
            enqueue(&myqueue,fetch);
        }

        oldlevel = level;
    }
    putchar('\n');
}


int initQ (Queue * queue)
{
    Qnode * fetch;
    if((fetch = (Qnode * )malloc(sizeof(Qnode))) == NULL)
        return 0;
    fetch->ptr = NULL;
    queue->thisQ =fetch;
    queue->rear = fetch;
    queue->front = fetch; // init the queue struct
    return 1;
}
int enqueue (Queue * queue,Qnode  qnode )
{
    Qnode * fetch;
    if( (fetch = (Qnode *)malloc(sizeof(Qnode))) == NULL)
        return 0;
    fetch->root = qnode.root;
    fetch->level = qnode.level;
    fetch->ptr = NULL;

    queue->rear->ptr = fetch;
    queue->rear = queue->rear->ptr;
    return 1;
}
int dequeue (Queue * queue,Qnode * qnode)
{
    Qnode * fetch;
    if(queue->front == queue->rear)
        return 0;
    fetch = queue->front->ptr;
    qnode->root = fetch->root;
    qnode->level = fetch->level;
    qnode->ptr = fetch->ptr;
    queue->front = queue->front->ptr;
    return 1;
}
int emptyQ(Queue * queue)
{
    if(queue->front == queue->rear)
        return 1;
    else 
        return 0;
}





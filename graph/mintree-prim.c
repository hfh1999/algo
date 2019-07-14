/* the prim*/
#define INF 10000
#define max 100
typedef struct graph{
    int n;// the number of nodes;
    int edge[max][max];
}graph;
void mintree(graph g,int node)
{
    int intree[max];//if 1,then the node is in the tree
    int mindis[max];//store the minum distance from the tree to the remain nodes

    int i,j,k;
    for(i = 0;i < g.n;i++) // initail opration
    {
        intree[i] = 0;
        mindis[i] = g.edge[node][i];
    }
    intree[node] = 1;
    buildtree(node);
    for(i=0;i<g.n-1;i++)
    {
        int min = INF;
        for(j=0;j<g.n;j++)
        {
            if(intree[j] == 0 && mindis[j] < min) // find the minum distace node from the tree;
            {
                min = mindis[j];
                k = j;
            }
        }
        intree[k] = 1; //place the node into the tree
        buildtree(k);
        

        for(i=0;i<g.n;i++) // the new in node intend to change the minum distance[]
        {
            if(intree[i] == 0 && g.edge[k][i] < mindis[i])
                mindis[i] = g.edge[k][i];
        }
    }
}

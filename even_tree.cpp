#include<iostream>
#include<cstring>
using namespace std;

struct Graph
{
    int V,E;
    int **adj;
};

struct Queue
{
    int rear,front,size;
    unsigned capacity;
    int *arr;

};

struct Queue *createQueue(unsigned capacity)
{
        struct Queue* q = new Queue();
        q->capacity =capacity;
        q->front =q->size =0;
        q->rear =q->capacity -1;
        q->arr =new int[100*q->capacity];
        return q;
}

int isempty(struct Queue *q)
{
    return (q->size ==0);
}
int isfull(struct Queue *q)
{
    return (q->size == q->capacity);
}

void enqueue(struct Queue *q,int data)
{
    if(isfull(q))
        return;
    q->rear = (q->rear + 1)%q->capacity;
    q->arr[q->rear] = data;
    q->size++;

}

int dequeue(struct Queue *q)
{
    if(isempty(q))
        return -32767;
    int item = q->arr[q->front];
    q->front = (q->front +1)%q->capacity;
    q->size--;
    return item;
}
struct Graph *matrix()
{
    int u,v;
    struct Graph *g = new Graph();
    cin >> g->V >> g->E;
    g->adj = new int*[g->V];
    for(int i=0;i<g->V;i++)
        g->adj[i] = new int[g->V];
    for(int i=0;i<g->V;i++)
        for(int j=0;j<g->V;j++)
            g->adj[i][j]=0;

    for(int i=0;i<g->E;i++) {
        cin >> u >> v;
//        g->adj[u-1][v-1] = 1;
        g->adj[v-1][u-1] = 1;
    }
    return g;

}

void bfs(struct Graph *g, struct Queue *q,int src)
{
    int vt[g->V];
    int child[g->V];
    memset(vt,0,sizeof(vt));
    memset(child,0,sizeof(child));
    enqueue(q,src);
//    vt[src] =1;
    while(q->size!=0) {
        int u = dequeue(q);
        for(int v =0 ;v < g->V; v++) {
            if(g->adj[u][v ] ) {
                child[u] = child[u] + 1;
          //      vt[v] =1;
                enqueue(q,v);
            }
        }
    }

    for(int i=0;i<g->V;i++)
        cout<<child[i] <<" ";

}
int main()
{
    struct Graph *g;
    struct Queue *q= createQueue(1000);
    g = matrix();
    bfs(g,q,0);
    return 0;
}

/*

10 9
2 1
3 1
4 3
5 2
6 1
7 2
8 6
9 8
10 8

*/

#include<iostream>
using namespace std;
struct Graph
{
    int V,E;
    int **adj;
};

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
        g->adj[u-1][v-1] = 6;
        g->adj[v-1][u-1] =6;
    }
    return g;

}

int minDistance(struct Graph *g,int dist[],bool sptset[])
{
    int min = 32767;
    int min_ind;
    for(int v=0; v < g->V;v++) {
        if(sptset[v] ==false && dist[v] <=min) {
            min = dist[v];
            min_ind = v;
        }
    }
    return min_ind;
}

void printSolution(struct Graph *g,int dist[],int src)
{

   for (int i = 0; i < g->V; i++) {

        if(i!=src) {
            if(dist[i] == 32767 )
                cout<<"-1 ";
            else
                cout<<dist[i]<<" ";
        }
   }

}
void dijkstra(struct Graph *g,int src)
{
    bool sptset[g->V];
    int dist[g->V];
    for(int i =0;i < g->V;i++) {
       sptset[i] =false;
       dist[i] = 32767;
    }

    dist[src] = 0;
    for(int i =0; i < g->V-1; i++) {
        int u = minDistance(g,dist,sptset);
        sptset[u] = true;

        for(int v = 0; v < g->V ; v++) {
            if(!sptset[v] && g->adj[u][v] && dist[u]!=32767 && dist[v] > dist[u] + g->adj[u][v])
                dist[v] = dist[u] + g->adj[u][v];
        }
    }
    printSolution(g,dist,src);
}


int main()
{
    int t;
    cin >>t;
    while(t--) {
        struct Graph *g;
        g = matrix();
        int s;
        cin >> s;
        dijkstra(g,s-1);
        cout<<endl;
    }

    return 0;

}

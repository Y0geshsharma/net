#include <stdio.h>
#include <limits.h>
int main()
{
    int src, V, i, j, count, min, v, u, min_index;
    printf("ENTER THE NUMBER OF NODES : ");
    scanf("%d", &V);
    int graph[V][V], dist[V];
    bool sptSet[V];
    printf("ENTER THE WEIGHTED ADJACENCY MATRIX : \n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);
    }
    printf("ENTER THE SOURCE NODE : ");
    scanf("%d", &src);
    for (i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (count = 0; count < V-1; count++)
    {
        min = INT_MAX, min_index;
        for (v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
        u = min_index;
        sptSet[u] = true;
        for (v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printf("Vertex Distance from Source\n");
    for (i = 0; i < V; i++)
        printf("%d tt %d\n", i, dist[i]);
	return 0;
}
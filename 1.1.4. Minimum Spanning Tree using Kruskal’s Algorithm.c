#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void kruskalMST(int **cost, int V) {

	
	

    int parent[100];
    int i, j;
    int min, u = -1, v = -1;
    int mincost = 0;
    int edge = 0;

    
    for (i = 0; i < V; i++)
        parent[i] = i;

    while (edge < V - 1)
    {
        min = 9999;

        
        for (i = 0; i < V; i++)
        {
            for (j = i + 1; j < V; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // Find root of u
        int ru = u;
        while (parent[ru] != ru)
            ru = parent[ru];

        // Find root of v
        int rv = v;
        while (parent[rv] != rv)
            rv = parent[rv];

        
        if (ru != rv)
        {
            parent[rv] = ru;
            printf("Edge %d:(%d, %d) cost:%d\n", edge, u, v, min);
            mincost += min;
            edge++;
        }

        
        cost[u][v] = 9999;
        cost[v][u] = 9999;
    }

    printf("Minimum cost= %d\n", mincost);

}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}

#include <stdio.h>
    for (int i = 1; i <= V - 1; i++) {
        int updated = 0;

        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                updated = 1;
            }
        }

        if (!updated)
            break;
    }

    // Check for negative cycle
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Negative cycle detected\n");
            return 0;
        }
    }

    // Print paths
    for (int v = 1; v <= V; v++) {
        if (v == source)
            continue;

        if (dist[v] == INT_MAX) {
            printf("%d INF None\n", v);
        } else {
            int path[V + 1];
            int count = 0;
            int current = v;

            while (current != -1) {
                path[count++] = current;
                current = parent[current];
            }

            printf("%d %d ", v, dist[v]);

            for (int i = count - 1; i >= 0; i--) {
                printf("%d", path[i]);

                if (i != 0)
                    printf("->");
            }

            printf("\n");
        }
    }

    return 0;
}

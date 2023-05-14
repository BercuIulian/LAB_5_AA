#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

// Dijkstra's algorithm implementation
void dijkstra(int graph[V][V], int start_node)
{
    int dist[V];
    bool visited[V];
    int i, j, min_dist, min_index;

    // Initialize distances and visited array
    for (i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[start_node] = 0;

    // Find shortest path for all vertices
    for (i = 0; i < V-1; i++)
    {
        // Find vertex with minimum distance
        min_dist = INT_MAX;
        for (j = 0; j < V; j++)
        {
            if (!visited[j] && dist[j] <= min_dist)
            {
                min_dist = dist[j];
                min_index = j;
            }
        }
        // Mark the selected vertex as visited
        visited[min_index] = true;

        // Update distances of adjacent vertices
        for (j = 0; j < V; j++)
        {
            if (!visited[j] && graph[min_index][j] != 0 &&
                dist[min_index] != INT_MAX && dist[min_index] + graph[min_index][j] < dist[j])
            {
                dist[j] = dist[min_index] + graph[min_index][j];
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances from node %d:\n", start_node);
    for (i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
        {
            printf("INF ");
        }
        else
        {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");
}

// Floyd-Warshall algorithm implementation
void floydWarshall(int graph[V][V])
{
    int dist[V][V];
    int i, j, k;

    // Initialize the distance matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Run the Floyd-Warshall algorithm
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances using Floyd-Warshall:\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INT_MAX)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int graph1[V][V] = {
        {0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 3, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}
    };



    int graph2[V][V] = {
        {0, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3},
        {1, 0, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3},
        {1, 2, 0, 1, 1, 2, 1, 2, 2, 2, 2, 3, 3, 3, 3},
        {2, 1, 1, 0, 2, 2, 1, 2, 2, 2, 2, 3, 3, 3, 3},
        {1, 2, 1, 2, 0, 1, 2, 1, 2, 2, 2, 3, 3, 3, 3},
        {1, 1, 2, 2, 1, 0, 1, 2, 1, 2, 2, 3, 3, 3, 3},
        {2, 2, 1, 1, 2, 1, 0, 1, 2, 1, 2, 3, 3, 3, 3},
        {2, 2, 2, 2, 1, 2, 1, 0, 1, 2, 1, 3, 3, 3, 3},
        {2, 2, 2, 2, 2, 1, 2, 1, 0, 1, 2, 3, 3, 3, 3},
        {2, 2, 2, 2, 2, 2, 1, 2, 1, 0, 1, 3, 3, 3, 3},
        {2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 0, 3, 3, 3, 3},
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 1, 1, 1},
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 0, 1, 1},
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 0, 1},
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 0}
    };




    // Run Dijkstra's algorithm on the sparse graph
    //dijkstra(graph1, 0);

    // Run Floyd-Warshall algorithm on the sparse graph
    //floydWarshall(graph1);

    // Run Dijkstra's algorithm on the dense graph
    //dijkstra(graph2, 0);

    // Run Floyd-Warshall algorithm on the dense graph
    floydWarshall(graph2);

    return 0;
}

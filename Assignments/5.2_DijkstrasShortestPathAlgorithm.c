#include <stdio.h>
#define INF 9999
int main(){
    int n;
    int graph[20][20];
    int distance[20], visited[20];
    int source;
    int i, j, c, min, next;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the weighted adjacency matrix:\n");
    printf("(Enter 0 if there is no direct road)\n");

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }
    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);
    for (i = 0; i < n; i++){
        distance[i] = graph[source][i];
        visited[i] = 0;
    }
    distance[source] = 0;
    visited[source] = 1;
    for (c = 1; c < n; c++){
        min = INF;
        next = -1;
        for (i = 0; i < n; i++){
            if (!visited[i] && distance[i] < min){
                min = distance[i];
                next = i;
            }
        }
        if (next == -1)
            break;
        visited[next] = 1;
        for (i = 0; i < n; i++){
            if (!visited[i] &&
                graph[next][i] != INF &&
                distance[next] + graph[next][i] < distance[i]){
                distance[i] = distance[next] + graph[next][i];
            }
        }
    }
    printf("\nShortest distances from vertex %d:\n", source);
    for (i = 0; i < n; i++){
        if (distance[i] == INF)
            printf("Vertex %d -> No path\n", i);
        else
            printf("Vertex %d -> %d\n", i, distance[i]);
    }
    return 0;
}

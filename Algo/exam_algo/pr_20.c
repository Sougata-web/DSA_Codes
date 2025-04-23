#include <stdio.h>
#define MAX 100

int visited[MAX];

void dfs(int graph[MAX][MAX], int n, int start) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < n; i++) {
        if (graph[start][i] && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}

void bfs(int graph[MAX][MAX], int n, int start) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++) visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS traversal: ");
    dfs(graph, n, start);
    printf("\n");

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);
    printf("BFS traversal: ");
    bfs(graph, n, start);
    printf("\n");

    return 0;
}

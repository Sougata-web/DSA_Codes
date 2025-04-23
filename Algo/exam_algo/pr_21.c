#include <stdio.h>
#define MAX 100
#define INF 999999

int graph[MAX][MAX];
int visited[MAX];

void prim(int n) {
    int no_edge = 0;
    int selected[MAX];
    for (int i = 0; i < n; i++) selected[i] = 0;

    selected[0] = 1;

    printf("Edge \tWeight\n");

    while (no_edge < n - 1) {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d\t%d\n", x, y, graph[x][y]);
        selected[y] = 1;
        no_edge++;
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }

    prim(n);
    return 0;
}

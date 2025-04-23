#include<stdio.h>
#define max 100
#define inf 999999

int graph[max][max];
int visited[max];

void prim(int n){
    int no_edge=0;
    int selected[max];
    for(int i=0;i<n;i++)
        selected[i]=0;
    selected[0]=1;
    printf("Edge \tWeight\n");

    while(no_edge < n-1){
        int min = inf;
        int x=0,y=0;
        for(int i=0; i<n;i++){
            if(selected[i]){
                for(int j=0;j<n;j++){
                    if(!selected[j] && graph[i][j]){
                        if(min> graph[i][j]){
                            min = graph[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        printf("%d - %d\t%d\n", x,y, graph[x][y]);
        selected[y]=1;
        no_edge++;
    }
}
int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &graph[i][j]);
            if(graph[i][j]==0)
            graph[i][j]=inf;
        }
    }
    prim(n);
    return 0;
}
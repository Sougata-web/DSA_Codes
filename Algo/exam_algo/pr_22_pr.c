#include <stdio.h>
#define max 100

int parent[max];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int edges[max][3], int e , int n){
    int count =0 ;
    int mincost=0;
    for(int i=0;i<n;i++){
        parent[i]=i;    
    }
    printf("Edge \tWeight\n");
    for(int i=0;count<n-1 && i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        int pu = find(u);
        int pv = find(v);

        if (pu != pv) {
            printf("%d - %d\t%d\n", u, v, w);
            mincost += w;
            union_set(pu, pv);
            count++;
        }
    }
    printf("Minimum Cost= %d\n",mincost);


}

void sort_edges(int edges[max][3], int e){
    for(int i=0;i<e-1;i++){
        for(int j=i+1;j<e;j++){
            if(edges[i][2]>edges[j][2]){
                int temp0 = edges[i][0];
                int temp1 = edges[i][1];
                int temp2 = edges[i][2];

                edges[i][0] = edges[j][0];
                edges[i][1] = edges[j][1];
                edges[i][2] = edges[j][2];

                edges[j][0] = temp0;
                edges[j][1] = temp1;
                edges[j][2] = temp2;
            }
        }
    }
}

int main()
{

    int n, e;
    int edges[max][3];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    sort_edges(edges, e);
    kruskal(edges, e, n);

    return 0;
}
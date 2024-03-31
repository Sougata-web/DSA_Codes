#include<stdio.h>
int main(){
    int c=5,r=6,i,j,a[r][c],k;
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            a[j][i]=(i*j+1);
        }
    }

    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
        int *base=&a[0][0];
    printf("%d",base+((i*5)+j)*sizeof(int));
    return 0;
}
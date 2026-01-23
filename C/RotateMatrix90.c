#include<stdio.h>

int main(){
    int n;
    printf("Enter number rows & columns : ");
    scanf("%d",&n);

    int a[n][n];

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("Enter Element : ");
            scanf("%d",&a[i][j]);
        }
    }

    printf("Original Matrix:\n");

    for (int k=0;k<n;k++){
        for (int l=0;l<n;l++){
            printf("%d ",a[k][l]);
        }
        printf("\n");
    }

    for (int s=0;s<n;s++){
        for (int t=0;t<s;t++){
            int temp = a[s][t];
            a[s][t] = a[t][s];
            a[t][s] = temp;
        }
    }

    for (int u=0;u<n;u++){
        for (int v=0,w=n-1;v<w;v++,w--){
            int temp = a[u][v];
            a[u][v] = a[u][w];
            a[u][w] = temp;
        }
    }

    printf("90 Degree Rotated Matrix:\n");

    for (int x=0;x<n;x++){
        for (int y=0;y<n;y++){
            printf("%d ",a[x][y]);
        }
        printf("\n");
    }
    return 0;
}
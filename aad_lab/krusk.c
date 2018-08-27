#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

int i,j,k,a,b,u,v,ne=1,n;
int min,mincost=0,cost[9][9],parent[9];


int find(int i){

    while(parent[i])
            i=parent[i];

    return i;
}

int uni(int i,int j){

    if(i!=j){
        parent[j]=i;
        return 1;
    }

    return 0;
}


int main()
{
    printf("\nEnter the no. of vertices:\n");
    scanf("%d",&n);
    
    printf("\nEnter the cost adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
		{
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            	cost[i][j]=INT_MAX;
        }

        printf("\nThe edges of Minimum Cost Spanning Tree are\n\n");
        while(ne<n){

                for(i=1,min=INT_MAX;i<=n;i++)
                            for(j=1;j<=n;j++)
                                if(cost[i][j]<min) {
                                        min=cost[i][j];
                                        a=i;
                                        b=j;
                                }


        u=find(a);
        v=find(b);
        if(uni(u,v)){

            printf("\n%d edge (%d,%d) =%d\n",ne++,a,b,min);
            mincost +=min;
        }


        cost[a][b]=cost[b][a]=INT_MAX;
    }

    printf("\n\tMinimum cost = %d\n",mincost);

    return 0;
}

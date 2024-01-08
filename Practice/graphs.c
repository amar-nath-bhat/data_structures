#include <stdio.h>
#include <stdlib.h>

void dfs(int a[][5], int vertices, int source){
    int visited[vertices], u, v, i;

    for(int i=0; i<vertices; i++)
        visited[i]=0;

    int Stack[10], top=-1;
    Stack[++top] = source;
    visited[source]=1;

    while(top>=0){
        u = Stack[top--];
        for(v=0; v<vertices; v++){
            if(a[u][v]==1 && visited[v]==0){
                visited[v]=1;
                Stack[++top]=v;
            }
        }
        printf("%d\t",u);
    }

}

void bfs(int a[][5], int vertices, int source){
    int visited[vertices], u, v, i;

    for(int i=0; i<vertices; i++)
        visited[i]=0;

    int Queue[10], r=-1, f=-1;

    Queue[++r] = source;
    visited[source]=1;

    while(f<r){
        u = Queue[++f];
        for(v=0; v<vertices; v++){
            if(a[u][v]==1 && visited[v]==0){
                visited[v] =1;
                Queue[++r] =v;
            }
        }
        printf("%d\t",u);
    }
}


int main(){
    int a[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            scanf("%d",&a[i][j]);
        }
    }

    bfs(a, 5, 0);
    return 0;
}
#include <stdio.h>

#define MAX 20

int main() {
    int adj[MAX][MAX], indegree[MAX];
    int n, i, j, count = 0;
    int topological[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    printf("\nTopological Order: ");

    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                topological[count++] = i;
                indegree[i] = -1;

                for(j = 0; j < n; j++) {
                    if(adj[i][j] == 1) {
                        indegree[j]--;
                    }
                }

                found = 1;
            }
        }

        if(!found) {
            printf("\nGraph contains a cycle\n");
            return 0;
        }
    }

    for(i = 0; i < n; i++) {
        printf("%d ", topological[i]);
    }

    return 0;
}

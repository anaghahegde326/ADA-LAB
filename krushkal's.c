#include <stdio.h>

#define MAX 20

struct Edge {
    int u, v, w;
};

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    parent[rootA] = rootB;
}

void sortEdges(struct Edge edges[], int e) {
    struct Edge temp;

    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, e;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    sortEdges(edges, e);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int minCost = 0;

    printf("Edges in Minimum Spanning Tree:\n");

    for (int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int setU = find(u);
        int setV = find(v);

        if (setU != setV) {
            printf("%d - %d : %d\n", u, v, edges[i].w);

            minCost += edges[i].w;

            unionSet(setU, setV);
        }
    }

    printf("Minimum Cost = %d\n", minCost);

    return 0;
}


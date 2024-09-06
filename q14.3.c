//Generating Minimum Spanning Tree using kruskals algorithm.
#include <stdio.h>

#define V 5 // Number of vertices

// Union-Find functions for Kruskal's algorithm
int find(int parent[], int i) {
    if (parent[i] == i) return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Function to implement Kruskal's algorithm
void kruskal(int graph[V][V]) {
    int parent[V], rank[V];
    int edges[V * (V - 1) / 2][3]; // Edge list for Kruskal's algorithm
    int edgeCount = 0;

    // Initialize parent and rank
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Store all edges with their weights
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j]) {
                edges[edgeCount][0] = i;
                edges[edgeCount][1] = j;
                edges[edgeCount][2] = graph[i][j];
                edgeCount++;
            }
        }
    }

    // Sort edges based on weights
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                int temp[3];
                for (int k = 0; k < 3; k++) {
                    temp[k] = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp[k];
                }
            }
        }
    }

    printf("Edge \tWeight\n");
    int mst_weight = 0;
    for (int i = 0; i < edgeCount; i++) {
        int x = find(parent, edges[i][0]);
        int y = find(parent, edges[i][1]);

        if (x != y) {
            printf("%d - %d \t%d\n", edges[i][0], edges[i][1], edges[i][2]);
            mst_weight += edges[i][2];
            unionSet(parent, rank, x, y);
        }
    }
    printf("Weight of MST: %d\n", mst_weight);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    printf("Kruskal's Algorithm:\n");
    kruskal(graph);

    return 0;
}


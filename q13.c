#include <stdio.h>

#define N 3 // Number of elements in the set

// Function to print the relation matrix
void printRelation(int relation[N][N]) {
    printf("Relation Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", relation[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the relation is reflexive
int isReflexive(int relation[N][N]) {
    for (int i = 0; i < N; i++) {
        if (relation[i][i] != 1) return 0;
    }
    return 1;
}

// Function to check if the relation is symmetric
int isSymmetric(int relation[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (relation[i][j] != relation[j][i]) return 0;
        }
    }
    return 1;
}

// Function to check if the relation is transitive
int isTransitive(int relation[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (relation[i][j]) {
                for (int k = 0; k < N; k++) {
                    if (relation[j][k] && !relation[i][k]) return 0;
                }
            }
        }
    }
    return 1;
}

// Function to check if two relations are equivalent
int areEquivalent(int relation1[N][N], int relation2[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (relation1[i][j] != relation2[i][j]) return 0;
        }
    }
    return 1;
}

int main() {
    // Define two relations
    int relation1[N][N] = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 1}
    };

    int relation2[N][N] = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 1}
    };

    // Print the relations
    printf("Relation 1:\n");
    printRelation(relation1);
    printf("Relation 2:\n");
    printRelation(relation2);

    // Test properties of relation1
    printf("Relation 1 - Reflexive: %s\n", isReflexive(relation1) ? "Yes" : "No");
    printf("Relation 1 - Symmetric: %s\n", isSymmetric(relation1) ? "Yes" : "No");
    printf("Relation 1 - Transitive: %s\n", isTransitive(relation1) ? "Yes" : "No");

    // Check equivalence
    printf("Relations are %s\n", areEquivalent(relation1, relation2) ? "Equivalent" : "Not Equivalent");

    return 0;
}


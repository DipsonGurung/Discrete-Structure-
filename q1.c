//1.	Programs to implement set operations union, intersection, difference, and Cartesian product. 

#include <stdio.h>

// Function to print a set
void printSet(int set[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}

// Union of two sets
void unionSets(int setA[], int sizeA, int setB[], int sizeB) {
    int unionSet[200], sizeU = 0;

    // Add all elements of setA to unionSet
    for (int i = 0; i < sizeA; i++) {
        unionSet[sizeU++] = setA[i];
    }

    // Add elements from setB that are not in setA
    for (int i = 0; i < sizeB; i++) {
        int found = 0;
        for (int j = 0; j < sizeA; j++) {
            if (setB[i] == setA[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unionSet[sizeU++] = setB[i];
        }
    } 

    printf("Union: ");
    printSet(unionSet, sizeU);
}

// Intersection of two sets
void intersectionSets(int setA[], int sizeA, int setB[], int sizeB) {
    int intersectionSet[100], sizeI = 0;

    // Add elements that exist in both sets
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (setA[i] == setB[j]) {
                intersectionSet[sizeI++] = setA[i];
                break;
            }
        }
    }

    printf("Intersection: ");
    printSet(intersectionSet, sizeI);
}

// Difference between two sets (A - B)
void differenceSets(int setA[], int sizeA, int setB[], int sizeB) {
    int differenceSet[100], sizeD = 0;

    // Add elements from setA that are not in setB
    for (int i = 0; i < sizeA; i++) {
        int found = 0;
        for (int j = 0; j < sizeB; j++) {
            if (setA[i] == setB[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            differenceSet[sizeD++] = setA[i];
        }
    }

    printf("Difference (A - B): ");
    printSet(differenceSet, sizeD);
}

// Cartesian Product of two sets
void cartesianProduct(int setA[], int sizeA, int setB[], int sizeB) {
    printf("Cartesian Product: { ");
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            printf("(%d, %d) ", setA[i], setB[j]);
        }
    }
    printf("}\n");
}

int main() {
    int setA[100], setB[100], sizeA, sizeB;

    // Input Set A
    printf("Enter the number of elements in Set A: ");
    scanf("%d", &sizeA);
    printf("Enter elements of Set A: ");
    for (int i = 0; i < sizeA; i++) {
        scanf("%d", &setA[i]);
    }

    // Input Set B
    printf("Enter the number of elements in Set B: ");
    scanf("%d", &sizeB);
    printf("Enter elements of Set B: ");
    for (int i = 0; i < sizeB; i++) {
        scanf("%d", &setB[i]);
    }

    // Perform and display set operations
    unionSets(setA, sizeA, setB, sizeB);
    intersectionSets(setA, sizeA, setB, sizeB);
    differenceSets(setA, sizeA, setB, sizeB);
    cartesianProduct(setA, sizeA, setB, sizeB);

    return 0;
}


#include <stdio.h>

void fuzzyUnion(float setA[], float setB[], int size) {
    float unionSet[100];
    for (int i = 0; i < size; i++) {
        unionSet[i] = (setA[i] > setB[i]) ? setA[i] : setB[i];  // Max value
    }
    
    printf("Fuzzy Union: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", unionSet[i]);
    }
    printf("\n");
}

void fuzzyIntersection(float setA[], float setB[], int size) {
    float intersectionSet[100];
    for (int i = 0; i < size; i++) {
        intersectionSet[i] = (setA[i] < setB[i]) ? setA[i] : setB[i];  // Min value
    }

    printf("Fuzzy Intersection: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", intersectionSet[i]);
    }
    printf("\n");
}

void fuzzyComplement(float set[], int size) {
    float complementSet[100];
    for (int i = 0; i < size; i++) {
        complementSet[i] = 1 - set[i];  // 1 minus the element's value
    }

    printf("Fuzzy Complement: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", complementSet[i]);
    }
    printf("\n");
}

int main() {
    float setA[100], setB[100];
    int size, i;

    // Input for fuzzy set A
    printf("Enter the number of elements in the sets: ");
    scanf("%d", &size);

    printf("Enter the membership values for Fuzzy Set A: ");
    for (i = 0; i < size; i++) {
        scanf("%f", &setA[i]);
    }

    // Input for fuzzy set B
    printf("Enter the membership values for Fuzzy Set B: ");
    for (i = 0; i < size; i++) {
        scanf("%f", &setB[i]);
    }

    // Perform fuzzy set operations
    fuzzyUnion(setA, setB, size);
    fuzzyIntersection(setA, setB, size);
    fuzzyComplement(setA, size);  // Complement of Set A
    fuzzyComplement(setB, size);  // Complement of Set B

    return 0;
}


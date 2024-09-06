#include <stdio.h>
#define SIZE 3

// Function to perform Join (OR operation) on two Boolean matrices
void boolean_join(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = mat1[i][j] | mat2[i][j];  // OR operation
        }
    }
}

// Function to perform Product (AND operation) on two Boolean matrices
void boolean_product(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = mat1[i][j] & mat2[i][j];  // AND operation
        }
    }
}

// Function to perform Boolean Product (AND-OR multiplication) of two Boolean matrices
void boolean_matrix_product(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] |= (mat1[i][k] & mat2[k][j]);  // AND followed by OR
            }
        }
    }
}

// Function to print a matrix
void print_matrix(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[SIZE][SIZE] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 1, 0}
    };

    int mat2[SIZE][SIZE] = {
        {0, 1, 1},
        {1, 0, 1},
        {0, 1, 1}
    };

    int result[SIZE][SIZE];

    // Perform Join operation
    boolean_join(mat1, mat2, result);
    printf("Join (OR operation) result:\n");
    print_matrix(result);

    // Perform Product operation
    boolean_product(mat1, mat2, result);
    printf("\nProduct (AND operation) result:\n");
    print_matrix(result);

    // Perform Boolean Product operation
    boolean_matrix_product(mat1, mat2, result);
    printf("\nBoolean Product result:\n");
    print_matrix(result);

    return 0;
}


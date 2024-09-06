#include <stdio.h>

// Function to print truth table for AND, OR, NOT operations
void generate_truth_table() {
    int p, q;

    // Print header
    printf("P | Q | P AND Q | P OR Q | NOT P\n");
    printf("-----------------------------\n");

    // Loop through all possible truth values of P and Q
    for (p = 0; p <= 1; p++) {
        for (q = 0; q <= 1; q++) {
            printf("%d | %d |   %d    |   %d   |   %d\n", 
                    p, q, (p && q), (p || q), !p);
        }
    }
}

int main() {
    generate_truth_table();
    return 0;
}


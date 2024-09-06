#include <stdio.h>

// Function to evaluate implication (P -> Q)
int implication(int p, int q) {
    return !p || q;
}

// Function to generate the truth table and check validity
void test_argument_validity() {
    int p, q;
    int valid = 1;  // Start by assuming the argument is valid

    // Print header
    printf("P | Q | P -> Q | P | Q (Conclusion)\n");
    printf("------------------------------\n");

    // Loop through all possible truth values of P and Q
    for (p = 0; p <= 1; p++) {
        for (q = 0; q <= 1; q++) {
            int premise1 = implication(p, q);  // P -> Q
            int conclusion = q;  // Conclusion Q

            printf("%d | %d |   %d   | %d |    %d\n", p, q, premise1, p, conclusion);

            // Argument is valid if whenever both premises are true, conclusion is also true
            if (premise1 && p && !conclusion) {
                valid = 0;  // Found a case where premises are true and conclusion is false
            }
        }
    }

    // Output result
    if (valid) {
        printf("\nThe argument is valid.\n");
    } else {
        printf("\nThe argument is invalid.\n");
    }
}

int main() {
    test_argument_validity();
    return 0;
}


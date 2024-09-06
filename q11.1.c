//permutation
#include <stdio.h>
#include <string.h>

// Function to swap two characters
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Recursive function to generate permutations
void generate_permutations(char *str, int start, int end) {
    if (start == end) {
        printf("%s\n", str);
    } else {
        for (int i = start; i <= end; i++) {
            swap((str + start), (str + i));
            generate_permutations(str, start + 1, end);
            swap((str + start), (str + i)); // Backtrack
        }
    }
}

int main() {
    char str[] = "ABC";
    int n = strlen(str);
    printf("Permutations of %s:\n", str);
    generate_permutations(str, 0, n - 1);
    return 0;
}


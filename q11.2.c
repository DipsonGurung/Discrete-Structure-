//combination
#include <stdio.h>

// Recursive function to generate combinations
void generate_combinations(char arr[], char data[], int start, int end, int index, int r) {
    if (index == r) {
        for (int j = 0; j < r; j++) {
            printf("%c", data[j]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        generate_combinations(arr, data, i + 1, end, index + 1, r);
    }
}

int main() {
    char arr[] = {'A', 'B', 'C', 'D'};
    int r = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    char data[r];
    
    printf("Combinations of 2 from ABCD:\n");
    generate_combinations(arr, data, 0, n - 1, 0, r);
    
    return 0;
}


#include <stdio.h>

// Function to find floor value
int findFloor(float num) {
    int result = (int)num;
    if (num < result) {
        result--; // If the number is less than the integer part, reduce it by 1
    }
    return result;
}

// Function to find ceiling value
int findCeiling(float num) {
    int result = (int)num;
    if (num > result) {
        result++; // If the number is greater than the integer part, increase it by 1
    }
    return result;
}

int main() {
    float number;

    printf("Enter a decimal number: ");
    scanf("%f", &number);

    printf("Floor of %.2f: %d\n", number, findFloor(number));
    printf("Ceiling of %.2f: %d\n", number, findCeiling(number));

    return 0;
}


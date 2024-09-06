#include <stdio.h>

// Function to perform binary addition
int binary_add(int a, int b) {
    int carry;
    while (b != 0) {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

// Function to perform binary multiplication
int binary_multiply(int a, int b) {
    int result = 0;
    while (b > 0) {
        if (b & 1)
            result = binary_add(result, a);
        a <<= 1;
        b >>= 1;
    }
    return result;
}

// Function to perform binary division
int binary_divide(int a, int b) {
    int quotient = 0;
    int temp = 1;

    while (b <= a) {
        b <<= 1;
        temp <<= 1;
    }
    while (temp > 1) {
        b >>= 1;
        temp >>= 1;
        if (a >= b) {
            a -= b;
            quotient += temp;
        }
    }
    return quotient;
}

int main() {
    int a = 10, b = 2;

    printf("Binary Addition of %d and %d: %d\n", a, b, binary_add(a, b));
    printf("Binary Multiplication of %d and %d: %d\n", a, b, binary_multiply(a, b));
    printf("Binary Division of %d by %d: %d\n", a, b, binary_divide(a, b));

    return 0;
}


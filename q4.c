#include <stdio.h>

// Function to find GCD using Euclidean algorithm
int euclideanGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Extended Euclidean Algorithm function
int extendedEuclideanGCD(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    
    int x1, y1;
    int gcd = extendedEuclideanGCD(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b;
    int x, y;
    
    // Input two integers
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    // Euclidean Algorithm for GCD
    int gcd = euclideanGCD(a, b);
    printf("GCD of %d and %d using Euclidean algorithm: %d\n", a, b, gcd);
    
    // Extended Euclidean Algorithm for GCD and coefficients
    int gcdExtended = extendedEuclideanGCD(a, b, &x, &y);
    printf("GCD of %d and %d using Extended Euclidean algorithm: %d\n", a, b, gcdExtended);
    printf("Coefficients x and y such that %d*x + %d*y = GCD are: x = %d, y = %d\n", a, b, x, y);
    
    return 0;
}


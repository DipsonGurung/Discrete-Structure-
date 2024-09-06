#include <stdio.h>

// Recursive function to compute a^n
int power(int a, int n) {
    if (n == 0)
        return 1;
    return a * power(a, n - 1);
}
// Recursive function to compute b^n mod m
int mod_power(int b, int n, int m) {
    if (n == 0)
        return 1;
    int half = mod_power(b, n / 2, m);
    half = (half * half) % m;
    if (n % 2 != 0)
        half = (half * b) % m;
    return half;
}
// Recursive function to perform linear search
int linear_search(int arr[], int size, int key, int index) {
    if (index >= size)
        return -1;  // Key not found
    if (arr[index] == key)
        return index;  // Key found
    return linear_search(arr, size, key, index + 1);
}
int main() {
    int a = 2, n = 5;
    int b = 3, m = 7;
    int arr[] = {1, 5, 3, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    // Compute a^n
    printf("a^n = %d^%d = %d\n", a, n, power(a, n));

    // Compute b^n mod m
    printf("b^n mod m = %d^%d mod %d = %d\n", b, n, m, mod_power(b, n, m));

    // Perform linear search
    int result = linear_search(arr, size, key, 0);
    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found in the array\n", key);

    return 0;
}


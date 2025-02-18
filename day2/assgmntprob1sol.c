#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;  // Base case: factorial of 0 or 1 is 1
    }
    return n * factorial(n - 1);  // Recursive case
}

int main() {
    int num;

    // Take user input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate and print the factorial
    printf("Factorial of %d is %d\n", num, factorial(num));

    return 0;
}

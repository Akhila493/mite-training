#include <stdio.h>

float calculateFinalAmount(float billAmount) {
    float discount = 0.0;

    // Determine the discount based on the bill amount
    if (billAmount >= 500 && billAmount <= 1000) {
        discount = 0.10; // 10% discount
    } else if (billAmount > 1000) {
        discount = 0.20; // 20% discount
    }

    // Calculate the final amount after discount
    float finalAmount = billAmount - (billAmount * discount);
    return finalAmount;
}

int main() {
    float billAmount;

    // Input: Total bill amount
    printf("Enter total bill amount: ₹");
    scanf("%f", &billAmount);

    // Calculate the final payable amount
    float finalAmount = calculateFinalAmount(billAmount);

    // Output: Final payable amount
    if (billAmount >= 500 && billAmount <= 1000) {
        printf("Final Payable Amount: ₹%.2f (after 10%% discount)\n", finalAmount);
    } else if (billAmount > 1000) {
        printf("Final Payable Amount: ₹%.2f (after 20%% discount)\n", finalAmount);
    } else {
        printf("Final Payable Amount: ₹%.2f (no discount)\n", finalAmount);
    }

    return 0;
}

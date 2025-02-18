#include <stdio.h>
#include <string.h>

int main() {
    int paymentMethod;
    char cardNumber[17];
    char upiID[50];
    int bankChoice;

    printf("Select Payment Method (1-3):\n");
    printf("1 for Credit/Debit Card\n");
    printf("2 for UPI\n");
    printf("3 for Net Banking\n");
    scanf("%d", &paymentMethod);

    
    if (paymentMethod < 1 || paymentMethod > 3) {
        printf("Invalid payment method. Please try again.\n");
        return 0;
    }

    switch (paymentMethod) {
        case 1: 
            printf("Enter your 16-digit card number: ");
            scanf("%s", cardNumber);
           
            if (strlen(cardNumber) == 16) {
                printf("Payment Successful!\n");
            } else {
                printf("Transaction Failed. Please try again.\n");
            }
            break;
        
        case 2:
            printf("Enter your UPI ID: ");
            scanf("%s", upiID);
          
            if (strchr(upiID, '@') != NULL) {
                printf("Payment Successful!\n");
            } else {
                printf("Transaction Failed. Please try again.\n");
            }
            break;
        
        case 3: 
            printf("Select a Bank:\n");
            printf("1 for SBI\n");
            printf("2 for HDFC\n");
            scanf("%d", &bankChoice);

            
            if (bankChoice == 1 || bankChoice == 2) {
                printf("Payment Successful!\n");
            } else {
                printf("Transaction Failed. Please try again.\n");
            }
            break;
    }

    return 0;
}

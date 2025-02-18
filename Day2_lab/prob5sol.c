#include <stdio.h>


float convertTemperature(float temp, int choice);


int main() {
    float temp;
    int choice;

    printf("Enter Temperature: ");
    scanf("%f", &temp);

   
    printf("Choose Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);

    
    float result = convertTemperature(temp, choice);
    if (choice == 1) {
        printf("Temperature in Fahrenheit: %.2f\n", result);
    } else if (choice == 2) {
        printf("Temperature in Celsius: %.2f\n", result);
    } else if (choice == 3) {
        printf("Temperature in Kelvin: %.2f\n", result);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}


float convertTemperature(float temp, int choice) {
    float result;

    switch (choice) {
        case 1: 
            result = (temp * 9 / 5) + 32;
            break;
        case 2: 
            result = (temp - 32) * 5 / 9;
            break;
        case 3: 
            result = temp + 273.15;
            break;
        default:
            result = -1;
    }

    return result;
}

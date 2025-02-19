#include <stdio.h>

#define SIZE 5  // Define the number of matches

int main() {
    int scores[SIZE];
    int i, highest, lowest;
    float sum = 0, average;
    
    // Input scores
    printf("Enter scores of %d matches: ", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &scores[i]);
    }
    
    // Initialize highest and lowest with the first element
    highest = lowest = scores[0];
    
    // Compute highest, lowest, and sum
    for (i = 0; i < SIZE; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
        sum += scores[i];
    }
    
    // Calculate average
    average = sum / SIZE;
    
    // Display results
    printf("Highest Score: %d\n", highest);
    printf("Lowest Score: %d\n", lowest);
    printf("Average Score: %.2f\n", average);
    
    return 0;
}

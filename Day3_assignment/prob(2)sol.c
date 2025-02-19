#include <stdio.h>
#include <string.h>

// Function to count occurrences of a pattern in a DNA sequence
int countPatternOccurrences(const char *dna, const char *pattern) {
    int count = 0;
    int dnaLength = strlen(dna);
    int patternLength = strlen(pattern);
    
    for (int i = 0; i <= dnaLength - patternLength; i++) {
        if (strncmp(&dna[i], pattern, patternLength) == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    char dna[100], pattern[20];
    
    // Get DNA sequence from user
    printf("Enter DNA Sequence: ");
    scanf("%s", dna);
    
    // Get pattern to search for
    printf("Enter pattern to search: ");
    scanf("%s", pattern);
    
    // Count occurrences
    int occurrences = countPatternOccurrences(dna, pattern);
    
    // Display result
    printf("Pattern found %d time(s) in the DNA sequence.\n", occurrences);
    
    return 0;
}

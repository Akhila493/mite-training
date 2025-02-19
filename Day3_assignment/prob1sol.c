#include <stdio.h>
#include <string.h>

#define MAX_PASSENGERS 100
#define NAME_LENGTH 50
#define DESTINATION_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    char destination[DESTINATION_LENGTH];
} Passenger;

void addPassenger(Passenger passengers[], int *count) {
    if (*count >= MAX_PASSENGERS) {
        printf("Cannot add more passengers. Maximum limit reached.\n");
        return;
    }
    
    printf("Passenger %d:\n", *count + 1);
    printf("Enter name: ");
    scanf("%s", passengers[*count].name);
    printf("Enter age: ");
    scanf("%d", &passengers[*count].age);
    printf("Enter destination: ");
    scanf("%s", passengers[*count].destination);
    
    (*count)++;
}

void sortPassengers(Passenger passengers[], int count) {
    Passenger temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(passengers[i].destination, passengers[j].destination) > 0) {
                // Swap passengers
                temp = passengers[i];
                passengers[i] = passengers[j];
                passengers[j] = temp;
            }
        }
    }
}

void searchPassengers(Passenger passengers[], int count, const char *destination) {
    int found = 0;
    printf("Passengers traveling to %s:\n", destination);
    for (int i = 0; i < count; i++) {
        if (strcmp(passengers[i].destination, destination) == 0) {
            printf("%s\n", passengers[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No passengers found traveling to %s.\n", destination);
    }
}

int main() {
    Passenger passengers[MAX_PASSENGERS];
    int count = 0;
    int n;

    printf("Enter number of passengers: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        addPassenger(passengers, &count);
    }

    sortPassengers(passengers, count);
    
    printf("\nSorted List (by destination):\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", passengers[i].name, passengers[i].destination);
    }

    char searchDestination[DESTINATION_LENGTH];
    printf("\nEnter destination to search: ");
    scanf("%s", searchDestination);
    
    searchPassengers(passengers, count, searchDestination);

    return 0;
}

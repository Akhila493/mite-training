#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a song node
typedef struct Song {
    char name[50];
    struct Song* next;
} Song;

Song* createSong(char* name) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->name, name);
    newSong->next = NULL;
    return newSong;
}

// Insert a song at the end of the circular linked list
void insertSong(Song** last, char* name) {
    Song* newSong = createSong(name);
    if (*last == NULL) {
        newSong->next = newSong;
        *last = newSong;
    } else {
        newSong->next = (*last)->next;
        (*last)->next = newSong;
        *last = newSong;
    }
}

// Display the currently playing song
void displayCurrentSong(Song* current) {
    if (current) {
        printf("Currently Playing: %s\n", current->name);
    } else {
        printf("No songs in the playlist!\n");
    }
}

// Move to the next song
Song* nextSong(Song* current) {
    if (current) {
        return current->next;
    }
    return NULL;
}

int main() {
    Song* last = NULL;
    Song* current = NULL;

    // Adding songs to the playlist
    insertSong(&last, "Song A");
    insertSong(&last, "Song B");
    insertSong(&last, "Song C");

    // Start playing from the first song
    if (last) {
        current = last->next;
    }

    // Simulate playing next song
    for (int i = 0; i < 5; i++) {
        displayCurrentSong(current);
        current = nextSong(current);
    }

    return 0;
}

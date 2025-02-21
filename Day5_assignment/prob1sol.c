#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 100
#define URL_LENGTH 100

typedef struct {
    char urls[MAX_HISTORY][URL_LENGTH];
    int top;
} Stack;

void push(Stack *stack, const char *url) {
    if (stack->top < MAX_HISTORY - 1) {
        stack->top++;
        strcpy(stack->urls[stack->top], url);
    } else {
        printf("History is full!\n");
    }
}

char* pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->urls[stack->top--];
    }
    return NULL;
}

char* peek(Stack *stack) {
    if (stack->top >= 0) {
        return stack->urls[stack->top];
    }
    return NULL;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int main() {
    Stack backStack = {.top = -1};
    Stack forwardStack = {.top = -1};
    char currentURL[URL_LENGTH] = "";
    int choice;
    char url[URL_LENGTH];
   
    while (1) {
        printf("\n1. Visit URL\n2. Go Back\n3. Go Forward\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();
       
        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, URL_LENGTH, stdin);
                url[strcspn(url, "\n")] = 0;
               
                if (strlen(currentURL) > 0) {
                    push(&backStack, currentURL);
                }
                strcpy(currentURL, url);
                forwardStack.top = -1; // Clear forward stack
                printf("Current Page: %s\n", currentURL);
                break;
           
            case 2:
                if (!isEmpty(&backStack)) {
                    push(&forwardStack, currentURL);
                    strcpy(currentURL, pop(&backStack));
                    printf("Current Page: %s\n", currentURL);
                } else {
                    printf("No pages to go back to!\n");
                }
                break;
           
            case 3:
                if (!isEmpty(&forwardStack)) {
                    push(&backStack, currentURL);
                    strcpy(currentURL, pop(&forwardStack));
                    printf("Current Page: %s\n", currentURL);
                } else {
                    printf("No pages to go forward to!\n");
                }
                break;
           
            case 4:
                exit(0);
               
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

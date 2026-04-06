#include <stdio.h>
#include <string.h>
#define MAX 5
#define SIZE 50
char queue[MAX][SIZE];
int front = -1, rear = -1;

void addDocument() {
    if (rear == MAX - 1) {
        printf("Printer Queue is Full\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    printf("Enter document name: ");
    scanf("%s", queue[rear]);
    printf("Document added to queue\n");
}

void printDocument() {
    if (front == -1 || front > rear) {
        printf("No documents to print\n");
        return;
    }

    printf("Printing document: %s\n", queue[front]);
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

void displayQueue() {
    int i;

    if (front == -1) {
        printf("No pending documents\n");
        return;
    }

    printf("Pending documents are:\n");
    for (i = front; i <= rear; i++) {
        printf("%s\n", queue[i]);
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Printer Queue Menu ---\n");
        printf("1. Add document to queue\n");
        printf("2. Print document\n");
        printf("3. Display pending documents\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDocument();
                break;
            case 2:
                printDocument();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}



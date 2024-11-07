
#include <stdio.h>
#include <stdlib.h>

struct snode {
    int data;
    struct snode *next;
};

struct snode* createNode(int data) {
    struct snode *newNode = (struct snode *)malloc(sizeof(struct snode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct snode **head, int data) {
    struct snode *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(struct snode *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct snode *temp = head;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct snode* reverseList(struct snode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct snode *rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main() {
    struct snode *head = NULL;
    int choice, item;

    do {
        printf("\nMenu:\n");
        printf("1. Push element to the list\n");
        printf("2. Reverse the list\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter item to push: ");
            scanf("%d", &item);
            push(&head, item);
            break;

        case 2:
            head = reverseList(head);
            printf("List reversed.\n");
            break;

        case 3:
            printf("Current list: ");
            printList(head);
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

//Write a program to implement a dequeue with the help of a linked list. input given by user

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a deque node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Define a structure for the deque
typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

// Initialize the deque
void initDeque(Deque* dq) {
    dq->front = NULL;
    dq->rear = NULL;
}

// Check if the deque is empty
int isEmpty(Deque* dq) {
    return dq->front == NULL;
}

// Insert an element at the front of the deque
void insertFront(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
}

// Insert an element at the rear of the deque
void insertRear(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

// Delete an element from the front of the deque
int deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }

    Node* temp = dq->front;
    int value = temp->data;

    if (dq->front == dq->rear) {
        dq->front = dq->rear = NULL;
    } else {
        dq->front = temp->next;
        dq->front->prev = NULL;
    }

    free(temp);
    return value;
}

// Delete an element from the rear of the deque
int deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }

    Node* temp = dq->rear;
    int value = temp->data;

    if (dq->front == dq->rear) {
        dq->front = dq->rear = NULL;
    } else {
        dq->rear = temp->prev;
        dq->rear->next = NULL;
    }

    free(temp);
    return value;
}

// Display the elements in the deque
void display(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements (from front to rear): ");
    Node* current = dq->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    int choice, value;

    while (1) {
        printf("\nDouble-Ended Queue Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                value = deleteFront(&dq);
                if (value != -1) {
                    printf("Deleted element from front: %d\n", value);
                }
                break;
            case 4:
                value = deleteRear(&dq);
                if (value != -1) {
                    printf("Deleted element from rear: %d\n", value);
                }
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

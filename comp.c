#include <stdio.h>
#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

int isEqual(Queue *q1, Queue *q2) {
    if (isEmpty(q1) && isEmpty(q2)) {
        return 1; // Both queues are empty and therefore equal
    }

    if ((q1->rear - q1->front) != (q2->rear - q2->front)) {
        return 0; // Sizes are different, so not equal
    }

    for (int i = q1->front, j = q2->front; i <= q1->rear; i++, j++) {
        if (q1->items[i] != q2->items[j]) {
            return 0; // Elements are different, so not equal
        }
    }

    return 1; // Queues are equal
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    int num;

    // Input for first queue
    printf("Enter elements for the first queue:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &num);
        enqueue(&q1, num);
    }

    // Input for second queue
    printf("\nEnter elements for the second queue:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &num);
        enqueue(&q2, num);
    }

    // Compare the queues
    if (isEqual(&q1, &q2)) {
        printf("\nThe queues are equal.\n");
    } else {
        printf("\nThe queues are not equal.\n");
    }

    return 0;
}

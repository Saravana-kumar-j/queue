#include <stdio.h>
#define MAX_SIZE 10

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

int countItems(Queue *q) {
    if (isEmpty(q)) {
        return 0;
    } else {
        return (q->rear - q->front + 1);
    }
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
    Queue q;
    initQueue(&q);

    int num, count;

    // Input elements into the queue
    printf("Enter elements for the queue (maximum %d elements):\n", MAX_SIZE);
    while (1) {
        printf("Enter value (or -1 to stop): ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        enqueue(&q, num);
    }

    // Calculate the number of items
    count = countItems(&q);
    printf("\nNumber of items in the queue: %d\n", count);

    // Display the queue
    display(&q);

    return 0;
}

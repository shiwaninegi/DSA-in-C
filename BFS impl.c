#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Queue structure
typedef struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to enqueue an item
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to dequeue an item
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; // Error code
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

// Function to perform BFS
void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start) {
    bool visited[MAX_VERTICES] = {false};  // Array to track visited nodes
    Queue q;
    initQueue(&q);

    // Start with the given node
    enqueue(&q, start);
    visited[start] = true;

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        // Explore all neighbors of the current node
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    // Example graph (undirected)
    graph[0][1] = 1; graph[1][0] = 1;
    graph[0][2] = 1; graph[2][0] = 1;
    graph[1][3] = 1; graph[3][1] = 1;
    graph[2][4] = 1; graph[4][2] = 1;

    int vertices = 5;  // Total number of vertices in the graph
    int start = 0;     // Starting node for BFS

    printf("BFS starting from vertex %d:\n", start);
    bfs(graph, vertices, start);

    return 0;
}

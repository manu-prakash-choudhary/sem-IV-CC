#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum size of the queue

// Global variables for the circular queue
int queue[MAX];
int front = -1; // Index of the front element
int rear = -1;  // Index of the rear element

// Function to check if the queue is empty
int isEmpty()
{
    return front == -1;
}

// Function to check if the queue is full
int isFull()
{
    return (rear + 1) % MAX == front;
}

// Function to add an element to the queue (Enqueue)
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue overflow! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty())
    {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d enqueued to the queue\n", value);
}

// Function to remove an element from the queue (Dequeue)
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue underflow! Cannot dequeue\n");
        return -1;
    }
    int dequeuedValue = queue[front];
    if (front == rear)
    { // If the queue becomes empty
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
    printf("%d dequeued from the queue\n", dequeuedValue);
    return dequeuedValue;
}

// Function to get the front element of the queue
int getFront()
{
    if (isEmpty())
    {
        printf("Queue is empty! No front element\n");
        return -1;
    }
    return queue[front];
}

// Function to get the rear element of the queue
int getRear()
{
    if (isEmpty())
    {
        printf("Queue is empty! No rear element\n");
        return -1;
    }
    return queue[rear];
}

// Driver function to demonstrate the circular queue
int main()
{
    int choice, value;

    while (1)
    {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front Element\n");
        printf("4. Rear Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            value = getFront();
            if (value != -1)
            {
                printf("Front element is: %d\n", value);
            }
            break;
        case 4:
            value = getRear();
            if (value != -1)
            {
                printf("Rear element is: %d\n", value);
            }
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

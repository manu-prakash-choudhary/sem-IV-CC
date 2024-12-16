#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100 // Define maximum stack size

// Global variables
int stack[MAX_SIZE];
int minStack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow! Cannot push %d.\n", value);
        return;
    }
    top++;
    stack[top] = value;

    // Update the minStack
    if (top == 0 || value < minStack[top - 1]) {
        minStack[top] = value;
    } else {
        minStack[top] = minStack[top - 1];
    }

    printf("%d pushed to stack.\n", value);
}

int pop() {
    if (top == -1) {
        printf("Stack underflow! Cannot pop element.\n");
        return INT_MIN;
    }
    return stack[top--];
}

int getMin() {
    if (top == -1) {
        printf("Stack is empty! No minimum element.\n");
        return INT_MIN;
    }
    return minStack[top];
}

int peek() {
    if (top == -1) {
        printf("Stack is empty! No top element.\n");
        return INT_MIN;
    }
    return stack[top];
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Top element\n");
        printf("4. Minimum element\n");
        printf("5. Display stack\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != INT_MIN)
                    printf("Popped element: %d\n", value);
                break;
            case 3:
                value = peek();
                if (value != INT_MIN)
                    printf("Top element: %d\n", value);
                break;
            case 4:
                value = getMin();
                if (value != INT_MIN)
                    printf("Minimum element: %d\n", value);
                break;
            case 5:
                displayStack();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
// github.com/manu-prakash-choudhary/sem-IV-CC

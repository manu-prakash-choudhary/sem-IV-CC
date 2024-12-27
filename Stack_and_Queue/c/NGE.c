#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// dpaste.org/GtOKU
#define STACKSIZE 100

// Global stack and top variable
int stack[STACKSIZE];
int top = -1;

// Stack Functions to be used by printNGE()
void push(int x)
{
    if (top == STACKSIZE - 1)
    {
        printf("Error: Stack Overflow\n");
        exit(0);
    }
    stack[++top] = x;
}

bool isEmpty()
{
    return top == -1;
}

int pop()
{
    if (top == -1)
    {
        printf("Error: Stack Underflow\n");
        exit(0);
    }
    return stack[top--];
}

// https://dpaste.org/zVTPT
/* Function to print element and NGE pair for all elements of arr[] of size n */
void printNGE(int arr[], int n)
{
    int element, current;

    /* Push the first element onto the stack */
    push(arr[0]);

    // Iterate through the rest of the elements
    for (int i = 1; i < n; i++)
    {
        current = arr[i];

        if (!isEmpty())
        {
            // Pop elements while they are smaller than the current element
            element = pop();

            while (element < current)
            {
                printf("%d --> %d\n", element, current);
                if (isEmpty())
                    break;
                element = pop();
            }

            // If the popped element is greater, push it back
            if (element > current)
                push(element);
            
        }

        // Push the current element onto the stack
        push(current);
    }

    /* After iterating, the remaining elements in the stack do not have a current greater element */
    while (!isEmpty())
    {
        element = pop();
        
        printf("%d --> -1\n", element);
    }
}


int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printNGE(arr, n);

    return 0;
}

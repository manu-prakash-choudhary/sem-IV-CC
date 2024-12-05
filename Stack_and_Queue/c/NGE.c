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

/* Function to print element and NGE pair for all elements of arr[] of size n */
void printNGE(int arr[], int n)
{
    int element, next;

    /* Push the first element onto the stack */
    push(arr[0]);

    // Iterate through the rest of the elements
    for (int i = 1; i < n; i++)
    {
        next = arr[i];

        if (!isEmpty())
        {
            // Pop elements while they are smaller than the next element
            element = pop();

            while (element < next)
            {
                printf("%d --> %d\n", element, next);
                if (isEmpty())
                    break;
                element = pop();
            }

            // If the popped element is greater, push it back
            if (element > next)
                push(element);
            
        }

        // Push the current element onto the stack
        push(next);
    }

    /* After iterating, the remaining elements in the stack do not have a next greater element */
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

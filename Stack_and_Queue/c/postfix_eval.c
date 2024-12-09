#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Global stack and top variable
int stack[MAX];
int top = -1;

// Function to check if the stack is empty
int isEmpty()
{
    return top == -1;
}

// Function to check if the stack is full
int isFull()
{
    return top == MAX - 1;
}

// Function to push an element onto the stack
void push(int value)
{
    if (isFull())
    {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(const char *expression)
{
    for (int i = 0; expression[i] != '\0'; i++)
    {
        char ch = expression[i];

        if (isdigit(ch))
        {
            // Push operand onto the stack
            push(ch - '0'); // Convert char to int
        }
        else
        {
            // Operator encountered, pop two operands and perform operation
            int operand2 = pop();
            int operand1 = pop();

            switch (ch)
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                if (operand2 == 0)
                {
                    printf("Division by zero error\n");
                    exit(EXIT_FAILURE);
                }
                push(operand1 / operand2);
                break;
            default:
                printf("Unknown operator: %c\n", ch);
                exit(EXIT_FAILURE);
            }
        }
    }

    // The result will be the only element left in the stack
    return pop();
}

int main()
{
    const char *postfixExpression = "231*+9-"; // Equivalent to (2 + (3 * 1)) - 9 = -4

    int result = evaluatePostfix(postfixExpression);
    printf("Result of the postfix expression '%s' is: %d\n", postfixExpression, result);

    return 0;
}

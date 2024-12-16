#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100 // Maximum size of the stack


char stack[MAX];
int top = -1;

// Function to check if the stack is empty
int isStackEmpty()
{
    return top == -1;
}

// Function to check if the stack is full
int isStackFull()
{
    return top == MAX - 1;
}

// Push an element onto the stack
void push(char value)
{
    if (isStackFull())
    {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

// Pop an element from the stack
char pop()
{
    if (isStackEmpty())
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

// Peek the top element of the stack
char peek()
{
    if (isStackEmpty())
    {
        return '\0';
    }
    return stack[top];
}

// Function to get the precedence of operators
// github.com/manu-prakash-choudhary/sem-IV-CC
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to convert infix to postfix
void infixToPostfix(const char *infix, char *postfix)
{
    int j = 0; // Index for postfix array

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];


        if (isalnum(ch))
        {
            // Operand: Append to postfix expression
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            // Left parenthesis: Push onto the stack
            push(ch);
        }
        else if (ch == ')')
        {
            // Right parenthesis: Pop to postfix until '(' is found
            while (!isStackEmpty() && peek() != '(')
            {
                postfix[j++] = pop();
            }
            if (!isStackEmpty() && peek() == '(')
            {
                pop(); // Discard '('
            }
        }
        else if (isOperator(ch))
        {
            // Operator: Handle precedence and associativity
            while (!isStackEmpty() && precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators in the stack to the postfix expression
    while (!isStackEmpty())
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
}

// Driver function
int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove trailing newline

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

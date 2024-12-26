import java.util.Scanner;

public class InfixToPostfix {

    private static int MAX = 100; // Maximum size of the stack
    private static char[] stack = new char[MAX];
    private static int top = -1;

    // Function to check if the stack is empty
    private static boolean isStackEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    private static boolean isStackFull() {
        return top == MAX - 1;
    }

    // Push an element onto the stack
    private static void push(char value) {
        if (isStackFull()) {
            throw new RuntimeException("Stack overflow");
        }
        stack[++top] = value;
    }

    // Pop an element from the stack
    private static char pop() {
        if (isStackEmpty()) {
            throw new RuntimeException("Stack underflow");
        }
        return stack[top--];
    }

    // Peek the top element of the stack
    private static char peek() {
        if (isStackEmpty()) {
            return '\0'; // Null character
        }
        return stack[top];
    }

    // Function to get the precedence of operators
    private static int precedence(char op) {
        switch (op) {
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
    private static boolean isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
    }

    // Function to convert infix to postfix
    public static String infixToPostfix(String infix) {
        StringBuilder postfix = new StringBuilder();

        for (int i = 0; i < infix.length(); i++) {
            char ch = infix.charAt(i);

            if (Character.isLetterOrDigit(ch)) {
                // Operand: Append to postfix expression
                postfix.append(ch);
            } else if (ch == '(') {
                // Left parenthesis: Push onto the stack
                push(ch);
            } else if (ch == ')') {
                // Right parenthesis: Pop to postfix until '(' is found
                while (!isStackEmpty() && peek() != '(') {
                    postfix.append(pop());
                }
                if (!isStackEmpty() && peek() == '(') {
                    pop(); // Discard '('
                }
            } else if (isOperator(ch)) {
                // Operator: Handle precedence and associativity
                while (!isStackEmpty() && precedence(peek()) >= precedence(ch)) {
                    postfix.append(pop());
                }
                push(ch);
            }
        }

        // Pop remaining operators in the stack to the postfix expression
        while (!isStackEmpty()) {
            postfix.append(pop());
        }

        return postfix.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter an infix expression: ");
        String infix = scanner.nextLine();

        String postfix = infixToPostfix(infix);

        System.out.println("Postfix expression: " + postfix);
        scanner.close();
    }
}

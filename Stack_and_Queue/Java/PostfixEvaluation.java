import java.util.Scanner;
import java.util.Stack;
 
public class PostfixEvaluation {

    // Method to evaluate a postfix expression
    public static int evaluatePostfix(String expression) {
        Stack<Integer> stack = new Stack<>();
        
        for (int i = 0; i < expression.length(); i++) {
            char ch = expression.charAt(i);
            
            // If the character is an operand, push it onto the stack
            if (Character.isDigit(ch)) {
                stack.push(ch - '0'); // Convert char to int
            } 
            // If the character is an operator, pop two elements and apply the operation
            else {
                int operand2 = stack.pop();
                int operand1 = stack.pop();
                int result = 0;
                
                switch (ch) {
                    case '+':
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        if (operand2 != 0) {
                            result = operand1 / operand2;
                        } else {
                            throw new ArithmeticException("Division by zero is not allowed.");
                        }
                        break;
                    default:
                        throw new IllegalArgumentException("Invalid operator: " + ch);
                }
                stack.push(result);
            }
        }
        
        // The result of the evaluation is the last element in the stack
        return stack.pop();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a valid postfix expression (e.g., 23*54*+): ");
        String expression = sc.nextLine();
        
        try {
            int result = evaluatePostfix(expression);
            System.out.println("The result of the postfix expression is: " + result);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            sc.close();
        }
    }
}

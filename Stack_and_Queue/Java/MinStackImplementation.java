import java.util.Scanner;
import java.util.Stack;

class MinStack {
    private Stack<Integer> stack;
    private Stack<Integer> minStack;
    private int capacity;

    public MinStack(int capacity) {
        this.stack = new Stack<>();
        this.minStack = new Stack<>();
        this.capacity = capacity;
    }

    public void push(int value) {
        if (stack.size() == capacity) {
            System.out.println("Overflow! Stack is full.");
            return;
        }
        stack.push(value);
        if (minStack.isEmpty() || value <= minStack.peek()) {
            minStack.push(value);
        }
        else {
            minStack.push(minStack.peek());
        }
    }

    public void pop() {
        if (stack.isEmpty()) {
            System.out.println("Underflow! Stack is empty.");
            return;
        }
        stack.pop();
        minStack.pop();
        
    }

    public int top() {
        if (stack.isEmpty()) {
            System.out.println("Stack is empty.");
            return -1;
        }
        return stack.peek();
    }

    public int getMin() {
        if (minStack.isEmpty()) {
            System.out.println("Stack is empty. No minimum element.");
            return -1;
        }
        return minStack.peek();
    }

    public void display() {
        if (stack.isEmpty()) {
            System.out.println("Stack is empty.");
            return;
        }
        System.out.println("Stack elements: " + stack);
    }
}

public class MinStackImplementation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the capacity of the stack: ");
        int capacity = sc.nextInt();
        MinStack minStack = new MinStack(capacity);

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Push element");
            System.out.println("2. Pop element");
            System.out.println("3. Display stack");
            System.out.println("4. Top element");
            System.out.println("5. Minimum element");
            System.out.println("6. Exit");
            System.out.print("Choose an option: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to push: ");
                    int value = sc.nextInt();
                    minStack.push(value);
                    break;
                case 2:
                    minStack.pop();
                    break;
                case 3:
                    minStack.display();
                    break;
                case 4:
                    int top = minStack.top();
                    if (top != -1) {
                        System.out.println("Top element: " + top);
                    }
                    break;
                case 5:
                    int min = minStack.getMin();
                    if (min != -1) {
                        System.out.println("Minimum element: " + min);
                    }
                    break;
                case 6:
                    System.out.println("Exiting...");
                    sc.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}

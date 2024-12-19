import java.util.Stack;

public class NextGreaterElement {

    // Stack to be used by printNGE()
    private static Stack<Integer> stack = new Stack<>();

    // Function to print element and NGE pair for all elements of arr[]
    public static void printNGE(int[] arr, int n) {
        int element, current;

        // Push the first element onto the stack
        stack.push(arr[0]);

        // Iterate through the rest of the elements
        for (int i = 1; i < n; i++) {
            current = arr[i];

            if (!stack.isEmpty()) {
                // Pop elements while they are smaller than the current element
                element = stack.pop();

                while (element < current) {
                    System.out.println(element + " --> " + current);
                    if (stack.isEmpty()) {
                        break;
                    }
                    element = stack.pop();
                }

                // If the popped element is greater, push it back
                if (element > current) {
                    stack.push(element);
                }
            }

            // Push the current element onto the stack
            stack.push(current);
        }

        // After iterating, the remaining elements in the stack do not have a current
        // greater element
        while (!stack.isEmpty()) {
            element = stack.pop();
            System.out.println(element + " --> -1");
        }
    }

    public static void main(String[] args) {
        int[] arr = { 11, 13, 21, 3 };
        int n = arr.length;

        printNGE(arr, n);
    }
}

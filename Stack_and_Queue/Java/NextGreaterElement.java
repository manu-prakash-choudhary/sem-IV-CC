import java.util.Scanner;
import java.util.Stack;

public class NextGreaterElement {

    public static void findNGE(int[] arr) {
        int n = arr.length;
        int[] nge = new int[n]; // Array to store the results
        Stack<Integer> stack = new Stack<>(); // Stack to help with the computation

        // Iterate through the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Remove elements from the stack that are less than or equal to arr[i]
            while (!stack.isEmpty() && stack.peek() <= arr[i]) {
                stack.pop();
            }

            // If the stack is not empty, the top of the stack is the NGE
            if (!stack.isEmpty()) {
                nge[i] = stack.peek();
            } else {
                nge[i] = -1; // No NGE found
            }

            // Push the current element onto the stack
            stack.push(arr[i]);
        }

        // Print the results
        System.out.println("Element\tNGE");
        for (int i = 0; i < n; i++) {
            System.out.println(arr[i] + "\t" + nge[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of elements in the array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        findNGE(arr);
        sc.close();
    }
}

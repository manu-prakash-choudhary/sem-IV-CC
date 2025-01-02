import java.util.Scanner;

// Node structure for the BST
class Node {
    int data;
    Node left, right;

    public Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class BST {
    // Function to insert a node into the BST using a while loop
    public static Node insert(Node root, int data) {
        Node newNode = new Node(data);

        if (root == null) {
            // If the tree is empty, the new node becomes the root
            return newNode;
        }

        Node current = root;

        while (true) {
            if (data < current.data) {
                if (current.left == null) {
                    // If the left child is null, insert the new node here
                    current.left = newNode;
                    break;
                } else {
                    // Move to the left child
                    current = current.left;
                }
            } else {
                if (current.right == null) {
                    // If the right child is null, insert the new node here
                    current.right = newNode;
                    break;
                } else {
                    // Move to the right child
                    current = current.right;
                }
            }
        }

        return root;
    }

    // Function to search for a node in the BST
    public static void search(int key, Node root) {
        Node current = root;

        while (current != null) {
            if (key == current.data) {
                System.out.println("\n" + key + " is found in the BST.");
                return;
            } else if (key < current.data) {
                current = current.left;
            } else {
                current = current.right;
            }
        }

        System.out.println("\n" + key + " is not found in the BST.");
    }

    // Function to find height of the BST
    public static int height(Node root) {
        if (root == null) {
            return 0;
        }

        int leftHeight = height(root.left);
        int rightHeight = height(root.right);

        return Math.max(leftHeight, rightHeight) + 1;
    }

    // check if tree is valid BST or not if not return false else return true
    public static boolean isValidBST(Node root, int min, int max) {
        if (root == null) {
            return true;
        }

        if (root.data < min || root.data > max) {
            return false;
        }

        return isValidBST(root.left, min, root.data - 1) && isValidBST(root.right, root.data + 1, max);
    }

    // Function for in-order traversal of the BST
    public static void inorderTraversal(Node root) {
        if (root == null) {
            return;
        }

        inorderTraversal(root.left);
        System.out.print(root.data + " ");
        inorderTraversal(root.right);

    }

    // Function for pre-order traversal of the BST
    public static void preorderTraversal(Node root) {
        if (root == null) {
            return;
        }

        System.out.print(root.data + " ");
        preorderTraversal(root.left);
        preorderTraversal(root.right);
    }

    // Function for post-order traversal of the BST
    public static void postorderTraversal(Node root) {
        if (root == null) {
            return;
        }

        postorderTraversal(root.left);
        postorderTraversal(root.right);
        System.out.print(root.data + " ");
    }
    


    // Main function
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Node root = null;
        System.out.print("Enter the number of nodes: ");
        int n = sc.nextInt();

        System.out.println("Enter the values to insert into the BST:");
        for (int i = 0; i < n; i++) {
            int value = sc.nextInt();
            root = insert(root, value);
        }

        System.out.println("\nIn-order Traversal: ");
        inorderTraversal(root);

        // Example search
        search(12, root);

        sc.close();
    }
}

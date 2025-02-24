import java.util.*;

class Node {
    int data;
    Node left, right;

    // Constructor to create a new node
    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}





public class BST {

    // Function to create a new node
    public static Node createNode(int data) {
        return new Node(data);
    }

    // Function to insert a node into the BST using a while loop
    public static Node insert(Node root, int data) {
        Node newNode = createNode(data);

        if (root == null) {
            return newNode;
        }

        Node current = root;

        while (true) {
            if (data < current.data) {
                if (current.left == null) {
                    current.left = newNode;
                    break;
                } else {
                    current = current.left;
                }
            } else {
                if (current.right == null) {
                    current.right = newNode;
                    break;
                } else {
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

    // Function to find the height of the BST
    public static int height(Node root) {
        if (root == null) {
            return 0;
        }

        return 1 + Math.max(height(root.left), height(root.right));
    }

    // Function for in-order traversal of the BST
    public static void inorderTraversal(Node root) {
        if (root != null) {
            inorderTraversal(root.left);
            System.out.print(root.data + " ");
            inorderTraversal(root.right);
        }
    }

    // Function to check if the given tree is a valid BST
    public static boolean isValidBST(Node root) {
        return isValidBSTUtil(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private static boolean isValidBSTUtil(Node node, int min, int max) {
        if (node == null) {
            return true;
        }

        if (node.data <= min || node.data >= max) {
            return false;
        }

        return isValidBSTUtil(node.left, min, node.data) && isValidBSTUtil(node.right, node.data, max);
    }

    // Level order traversal of the BST
    public static void levelOrderTraversal(Node root) {
        if (root == null) {
            return;
        }

        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            Node current = queue.poll();
            System.out.print(current.data + " ");

            if (current.left != null) {
                queue.add(current.left);
            }

            if (current.right != null) {
                queue.add(current.right);
            }
        }
    }

    // Boundary Traversal BST
    public static void printLeftBoundary(Node root) {
        if (root != null) {
            if (root.left != null) {
                System.out.print(root.data + " ");
                printLeftBoundary(root.left);
            } else if (root.right != null) {
                System.out.print(root.data + " ");
                printLeftBoundary(root.right);
            }
        }
    }

    public static void printRightBoundary(Node root) {
        if (root != null) {
            if (root.right != null) {
                printRightBoundary(root.right);
                System.out.print(root.data + " ");
            } else if (root.left != null) {
                printRightBoundary(root.left);
                System.out.print(root.data + " ");
            }
        }
    }

    public static void printLeaves(Node root) {
        if (root != null) {
            printLeaves(root.left);

            if (root.left == null && root.right == null) {
                System.out.print(root.data + " ");
            }

            printLeaves(root.right);
        }
    }

    public static void BSTBoundaryTraversal(Node root) {
        if (root == null) {
            return;
        }

        System.out.println("\nBoundary Traversal of the BST:");
        System.out.print(root.data + " ");

        printLeftBoundary(root.left);
        printLeaves(root.left);
        printLeaves(root.right);
        printRightBoundary(root.right);
    }

    // Lowest Common Ancestor
    public static Node LCA(Node root, int n1, int n2) {
        if (root == null) {
            return null;
        }

        if (root.data > n1 && root.data > n2) {
            return LCA(root.left, n1, n2);
        }

        if (root.data < n1 && root.data < n2) {
            return LCA(root.right, n1, n2);
        }

        return root;
    }

    // Function to check if the given trees are mirror images of each other
    public static boolean isMirror(Node root1, Node root2) {
        if (root1 == null && root2 == null) {
            return true;
        }

        if (root1 == null || root2 == null) {
            return false;
        }

        return (root1.data == root2.data) && isMirror(root1.left, root2.right) && isMirror(root1.right, root2.left);
    }

    // Tree from left view
    public static void leftView(Node root, int level, int[] maxLevel) {
        if (root == null) {
            return;
        }

        if (maxLevel[0] < level) {
            System.out.print(root.data + " ");
            maxLevel[0] = level;
        }

        leftView(root.left, level + 1, maxLevel);
        leftView(root.right, level + 1, maxLevel);
    }

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

        search(12, root);
        System.out.println("\nHeight of the BST: " + height(root));

        System.out.println("Level Order Traversal: ");
        levelOrderTraversal(root);

        if (isValidBST(root)) {
            System.out.println("\n\nThe given tree is a valid BST.");
        } else {
            System.out.println("\n\nThe given tree is not a valid BST.");
        }

        BSTBoundaryTraversal(root);

        Node lca = LCA(root, 10, 15);
        if (lca != null) {
            System.out.println("\n\nLowest Common Ancestor of 10 and 15: " + lca.data);
        }

        Node root1 = createNode(1);
        root1.left = createNode(2);
        root1.right = createNode(3);
        root1.left.left = createNode(4);
        root1.left.right = createNode(5);

        Node root2 = createNode(1);
        root2.left = createNode(3);
        root2.right = createNode(2);
        root2.right.left = createNode(5);
        root2.right.right = createNode(4);

        if (isMirror(root1, root2)) {
            System.out.println("The trees are mirror images of each other.");
        } else {
            System.out.println("The trees are not mirror images of each other.");
        }

        int[] maxLevel = { 0 };
        System.out.println("\nLeft View of the BST: ");
        leftView(root, 1, maxLevel);

        sc.close();
    }
}

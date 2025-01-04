class Node {
    int data;
    Node next;

    // Constructor to create a new node
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class PairwiseSwapLinkedList {

    // Function to create a new node
    public static Node createNode(int data) {
        return new Node(data);
    }

    // Function to swap nodes in a pairwise manner
    public static Node pairwiseSwap(Node head) {
        if (head == null || head.next == null) {
            return head; // No swapping needed for 0 or 1 node
        }

        Node prev = null;
        Node curr = head;
        Node next = null;

        // Update the head to the second node
        head = head.next;

        while (curr != null && curr.next != null) {
            next = curr.next;
            curr.next = next.next;
            next.next = curr;

            if (prev != null) {
                prev.next = next;
            }

            prev = curr;
            curr = curr.next;
        }

        return head;
    }

    // Function to print the linked list
    public static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " -> ");
            head = head.next;
        }
        System.out.println("NULL");
    }

    public static void main(String[] args) {
        // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
        Node head = createNode(1);
        head.next = createNode(2);
        head.next.next = createNode(3);
        head.next.next.next = createNode(4);
        head.next.next.next.next = createNode(5);

        System.out.println("Original List:");
        printList(head);

        // Perform pairwise swapping
        head = pairwiseSwap(head);

        System.out.println("List After Pairwise Swap:");
        printList(head);
    }
}

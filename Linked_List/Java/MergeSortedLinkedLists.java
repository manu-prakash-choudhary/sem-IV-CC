class Node {
    int data;
    Node next;

    
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class MergeSortedLinkedLists {

    // Function to merge two sorted linked lists without a dummy node
    public static Node mergeSortedLists(Node LL1, Node LL2) {
        if (LL1 == null) return LL2;
        if (LL2 == null) return LL1;

        Node head; // Head of the merged list
        Node tail; // Tail of the merged list

        // Initialize the head and tail
        if (LL1.data <= LL2.data) {
            head = LL1;
            LL1 = LL1.next;
        } else {
            head = LL2;
            LL2 = LL2.next;
        }
        tail = head;

        // Merge the two lists
        while (LL1 != null && LL2 != null) {
            if (LL1.data <= LL2.data) {
                tail.next = LL1;
                LL1 = LL1.next;
            } else {
                tail.next = LL2;
                LL2 = LL2.next;
            }
            tail = tail.next;
        }

        // Attach the remaining nodes of LL1 or LL2
        if (LL1 != null) {
            tail.next = LL1;
        } else {
            tail.next = LL2;
        }

        return head;
    }

    // Function to print a linked list
    public static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " -> ");
            head = head.next;
        }
        System.out.println("NULL");
    }

    public static void main(String[] args) {
        // Creating first sorted linked list: 1 -> 3 -> 5
        Node LL1 = new Node(1);
        LL1.next = new Node(3);
        LL1.next.next = new Node(5);

        // Creating second sorted linked list: 2 -> 4 -> 6
        Node LL2 = new Node(2);
        LL2.next = new Node(4);
        LL2.next.next = new Node(6);

        System.out.print("List 1: ");
        printList(LL1);

        System.out.print("List 2: ");
        printList(LL2);

        // Merging the two lists
        Node mergedList = mergeSortedLists(LL1, LL2);

        System.out.print("Merged List: ");
        printList(mergedList);
    }
}

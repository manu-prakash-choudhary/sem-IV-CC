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
    public static Node mergeSortedLists(Node list1, Node list2) {
        if (list1 == null) return list2;
        if (list2 == null) return list1;

        Node head; // Head of the merged list
        Node tail; // Tail of the merged list

        // Initialize the head and tail
        if (list1.data <= list2.data) {
            head = list1;
            list1 = list1.next;
        } else {
            head = list2;
            list2 = list2.next;
        }
        tail = head;

        // Merge the two lists
        while (list1 != null && list2 != null) {
            if (list1.data <= list2.data) {
                tail.next = list1;
                list1 = list1.next;
            } else {
                tail.next = list2;
                list2 = list2.next;
            }
            tail = tail.next;
        }

        // Attach the remaining nodes of list1 or list2
        if (list1 != null) {
            tail.next = list1;
        } else {
            tail.next = list2;
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
        Node list1 = new Node(1);
        list1.next = new Node(3);
        list1.next.next = new Node(5);

        // Creating second sorted linked list: 2 -> 4 -> 6
        Node list2 = new Node(2);
        list2.next = new Node(4);
        list2.next.next = new Node(6);

        System.out.print("List 1: ");
        printList(list1);

        System.out.print("List 2: ");
        printList(list2);

        // Merging the two lists
        Node mergedList = mergeSortedLists(list1, list2);

        System.out.print("Merged List: ");
        printList(mergedList);
    }
}

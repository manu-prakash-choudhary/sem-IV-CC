/*
List 1 (ll1): 1 -> 3 -> 7 -> 10 
                                \
                                  -> 15 -> 20 -> 25
                                /
List 2 (ll2):       2 -> 6 -> 9 
in this case, the merge point is Node with data 15
 */

class Node {
    int data;
    Node next;

    // Constructor to create a new node
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class MergePointOfLinkedLists {

    // Function to create a new node
    

    // Function to find the length of a linked list
    public static int getLength(Node head) {
        int length = 0;
        while (head != null) {
            length++;
            head = head.next;
        }
        return length;
    }

    // Function to find the merge point of two linked lists
    public static Node findMergePoint(Node head1, Node head2) {
        int len1 = getLength(head1);
        int len2 = getLength(head2);

        // Align the starting points of both lists
        Node ptr1 = head1;
        Node ptr2 = head2;

        if (len1 > len2) {
            int diff = len1 - len2;
            while (diff-- > 0) {
                ptr1 = ptr1.next;
            }
        } else if (len2 > len1) {
            int diff = len2 - len1;
            while (diff-- > 0) {
                ptr2 = ptr2.next;
            }
        }

        // Traverse both lists together to find the merge point
        while (ptr1 != null && ptr2 != null) {
            if (ptr1 == ptr2) {
                return ptr1; // Merge point found
            }
            ptr1 = ptr1.next;
            ptr2 = ptr2.next;
        }

        return null; // No merge point found
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
        // Create two linked lists with a common merge point
        Node common = new Node(15);
        common.next = new Node(20);
        common.next.next = new Node(25);

        Node list1 = new Node(3);
        list1.next = new Node(6);
        list1.next.next = new Node(9);
        list1.next.next.next = common;

        Node list2 = new Node(10);
        list2.next = common;

        System.out.print("List 1: ");
        printList(list1);

        System.out.print("List 2: ");
        printList(list2);

        Node mergePoint = findMergePoint(list1, list2);

        if (mergePoint != null) {
            System.out.println("Merge point found at node with data: " + mergePoint.data);
        } else {
            System.out.println("No merge point found");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to find the length of a linked list
int getLength(struct Node *head)
{
    int length = 0;
    while (head)
    {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the merge point of two linked lists
struct Node *findMergePoint(struct Node *head1, struct Node *head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Align the starting points of both lists
    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;

    if (len1 > len2)
    {
        int diff = len1 - len2;
        while (diff--)
        {
            ptr1 = ptr1->next;
        }
    }
    else if (len2 > len1)
    {
        int diff = len2 - len1;
        while (diff--)
        {
            ptr2 = ptr2->next;
        }
    }

    // Traverse both lists together to find the merge point
    while (ptr1 && ptr2)
    {
        if (ptr1 == ptr2)
        {
            return ptr1; // Merge point found
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL; // No merge point found
}

// Function to print a linked list
void printList(struct Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver code
int main()
{
    // Create two linked lists with a common merge point
    struct Node *common = createNode(15);
    common->next = createNode(20);

    struct Node *list1 = createNode(3);
    list1->next = createNode(6);
    list1->next->next = createNode(9);
    list1->next->next->next = common;

    struct Node *list2 = createNode(10);
    list2->next = common;

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node *mergePoint = findMergePoint(list1, list2);

    if (mergePoint)
    {
        printf("Merge point found at node with data: %d\n", mergePoint->data);
    }
    else
    {
        printf("No merge point found\n");
    }

    return 0;
}

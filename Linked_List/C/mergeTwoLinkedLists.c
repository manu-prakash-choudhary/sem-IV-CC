#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node *list1, struct Node *list2)
{
    // Dummy node to simplify the merge logic
    struct Node dummy;
    struct Node *tail = &dummy;
    dummy.next = NULL;

    // Merge the two lists using a while loop
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining nodes of list1 or list2
    if (list1 != NULL)
    {
        tail->next = list1;
    }
    else
    {
        tail->next = list2;
    }

    return dummy.next;
}

// Function to print a linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    // Creating first sorted linked list: 1 -> 3 -> 5
    struct Node *list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    // Creating second sorted linked list: 2 -> 4 -> 6
    struct Node *list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Merging the two lists
    struct Node *mergedList = mergeSortedLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}

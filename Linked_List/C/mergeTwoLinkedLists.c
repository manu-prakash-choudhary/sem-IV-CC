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
struct Node* mergeSortedLists(struct Node *LL1, struct Node *LL2)
{
    
    
    if(LL1 == NULL)
    {
        return LL2;
    }
    if(LL2 == NULL)
    {
        return LL1;
    }


    // Create a dummy node to start the merged list
    struct Node *head = createNode(0);
    struct Node *tail = head;



    // Merge the two lists using a while loop
    while (LL1 != NULL && LL2 != NULL)
    {
        if (LL1->data <= LL2->data)
        {
            tail->next = LL1;
            LL1 = LL1->next;
        }
        else
        {
            tail->next = LL2;
            LL2 = LL2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining nodes of LL1 or LL2
    if (LL1 != NULL)
    {
        tail->next = LL1;
    }
    else
    {
        tail->next = LL2;
    }

    return head->next;
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
    struct Node *LL1 = createNode(1);
    LL1->next = createNode(3);
    LL1->next->next = createNode(5);

    // Creating second sorted linked list: 2 -> 4 -> 6
    struct Node *LL2 = createNode(2);
    LL2->next = createNode(4);
    LL2->next->next = createNode(6);

    printf("List 1: ");
    printList(LL1);

    printf("List 2: ");
    printList(LL2);

    // Merging the two lists
    struct Node *mergedList = mergeSortedLists(LL1, LL2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}

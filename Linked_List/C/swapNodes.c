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

// Function to swap nodes in a pairwise manner
struct Node *pairwiseSwap(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head; // No swapping needed for 0 or 1 node
    }

    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    // Update the head to the second node
    head = head->next;

    while (curr != NULL && curr->next != NULL)
    {
        next = curr->next;
        curr->next = next->next;
        next->next = curr;

        if (prev != NULL)
        {
            prev->next = next;
        }

        prev = curr;
        curr = curr->next;
    }

    return head;
}

// Function to print the linked list
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
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List:\n");
    printList(head);

    // Perform pairwise swapping
    head = pairwiseSwap(head);

    printf("List After Pairwise Swap:\n");
    printList(head);

    return 0;
}

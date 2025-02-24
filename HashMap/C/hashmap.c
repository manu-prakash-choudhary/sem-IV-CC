#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 // Size of the hash table

// Hash table (array of linked lists for collision handling)
struct Node
{
    int key;
    struct Node *next;
};

// Global hash table
struct Node *hashTable[TABLE_SIZE];

// Hash function: Computes index using modulus
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

// Insert key into the hash table
void insert(int key)
{
    int index = hashFunction(key);

    // Create new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;

    // Insert at the beginning of the list at index
    if (hashTable[index] == NULL)
    {
        hashTable[index] = newNode;
    }
    else
    {
        struct Node *temp = hashTable[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Search for a key in the hash table
int search(int key)
{
    int index = hashFunction(key);
    struct Node *temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->key == key)
            return 1; // Found
        temp = temp->next;
    }
    return 0; // Not found
}

// Delete a key from the hash table
void delete(int key)
{
    int index = hashFunction(key);
    struct Node *temp = hashTable[index];
    struct Node *prev = NULL;

    // Traverse the linked list at the index
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            // Found key, now delete it
            if (prev == NULL)
            {
                // Deleting first node in chain
                hashTable[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("Key %d deleted successfully.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Key %d not found.\n", key);
}

// Display the hash table
void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Index %d: ", i);
        struct Node *temp = hashTable[i];

        while (temp != NULL)
        {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function to test the hash table
int main()
{
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }

    // Insert values
    insert(10);
    insert(20);
    insert(15);
    insert(25);
    insert(30);

    // Display hash table
    printf("Hash Table before deletion:\n");
    display();

    // Search for a key
    int key = 20;
    if (search(key))
    {
        printf("Key %d found in hash table.\n", key);
    }
    else
    {
        printf("Key %d not found in hash table.\n", key);
    }

    // Delete a key
    delete (20);
    delete (50); // Non-existent key

    // Display after deletion
    printf("Hash Table after deletion:\n");
    display();

    return 0;
}

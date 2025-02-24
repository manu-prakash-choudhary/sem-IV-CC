#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26 // Assuming only lowercase letters a-z

// Trie Node structure
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord; // True if the word ends at this node
};

// Function to create a new Trie node
struct TrieNode *createNode()
{
    struct TrieNode *newNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (newNode)
    {
        newNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to insert a word into the Trie
void insert(struct TrieNode *root, const char *word)
{
    struct TrieNode *current = root;
    while (*word)
    {
        int index = *word - 'a';
        if (!current->children[index])
            current->children[index] = createNode();
        current = current->children[index];
        word++;
    }
    current->isEndOfWord = true;
}

// Function to search for a word in the Trie
bool search(struct TrieNode *root, const char *word)
{
    struct TrieNode *current = root;
    while (*word)
    {
        int index = *word - 'a';
        if (!current->children[index])
            return false;
        current = current->children[index];
        word++;
    }
    return current->isEndOfWord;
}

// Helper function to check if a node has any children
bool hasChildren(struct TrieNode *node)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (node->children[i])
            return true;
    return false;
}

// Function to remove a word from the Trie
bool removeWord(struct TrieNode *root, const char *word)
{
    if (!root)
        return false;

    if (*word)
    {
        int index = *word - 'a';
        if (root->children[index] && removeWord(root->children[index], word + 1))
        {
            free(root->children[index]);
            root->children[index] = NULL;

            // If the current node is not the end of another word and has no children, delete it
            return (!root->isEndOfWord && !hasChildren(root));
        }
    }
    else if (root->isEndOfWord)
    {
        root->isEndOfWord = false;

        // If the node has no children, return true to delete it
        return !hasChildren(root);
    }
    return false;
}

// Function to free the entire Trie
void freeTrie(struct TrieNode *root)
{
    if (!root)
        return;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        freeTrie(root->children[i]);
    free(root);
}

// Main function to test Trie operations
int main()
{
    struct TrieNode *root = createNode();

    // Insert words
    insert(root, "apple");
    insert(root, "banana");
    insert(root, "bat");
    insert(root, "ball");

    // Search words
    printf("Search apple: %s\n", search(root, "apple") ? "Found" : "Not Found");
    printf("Search bat: %s\n", search(root, "bat") ? "Found" : "Not Found");
    printf("Search ball: %s\n", search(root, "ball") ? "Found" : "Not Found");
    printf("Search cat: %s\n", search(root, "cat") ? "Found" : "Not Found");

    // Remove a word
    printf("\nRemoving 'bat'\n");
    removeWord(root, "bat");
    printf("Search bat: %s\n", search(root, "bat") ? "Found" : "Not Found");

    // Free the Trie
    freeTrie(root);
    return 0;
}

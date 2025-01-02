#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



// Node structure for the BST
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST using a while loop
struct Node *insert(struct Node *root, int data)
{
    struct Node *newNode = createNode(data);

    if (root == NULL)
    {
        // If the tree is empty, the new node becomes the root
        return newNode;
    }

    struct Node *current = root;

    while (1)
    {
        if (data < current->data)
        {
            if (current->left == NULL)
            {
                // If the left child is NULL, insert the new node here
                current->left = newNode;
                break;
            }
            else
            {
                // Move to the left child
                current = current->left;
            }
        }
        else
        {
            if (current->right == NULL)
            {
                // If the right child is NULL, insert the new node here
                current->right = newNode;
                break;
            }
            else
            {
                // Move to the right child
                current = current->right;
            }
        }
    }

    return root;
}

// Function to search for a node in the BST
void search(int key, struct Node *root)
{
    struct Node *current = root;

    while (current != NULL)
    {
        if (key == current->data)
        {
            printf("\n%d is found in the BST.\n", key);
            return;
        }
        else if (key < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    printf("\n%d is not found in the BST.\n", key);
}

// Function to find height of the BST
int height(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int leftHeight = 1;
    int rightHeight = 1;

    while(root->left != NULL || root->right != NULL)
    {
        if(root->left != NULL)
        {
            leftHeight++;
            root = root->left;
        }
        if(root->right != NULL)
        {
            rightHeight++;
            root = root->right;
        }
    }

    if(leftHeight > rightHeight)
    {
        return leftHeight;
    }
    else
    {
        return rightHeight;
    }
    // OR return leftHeight > rightHeight ? leftHeight : rightHeight; Both are same;
}

// Function for in-order traversal of the BST
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// isValidBST function to check if the given tree is a valid BST or not
int isValidBST(struct Node *root)
{
    return isValidBSTUtil(root, INT_MIN, INT_MAX);
}

// isValidBSTUtil function to check if the given tree is a valid BST or not
int isValidBSTUtil(struct Node *curr, int min, int max)
{
    if (curr == NULL)
    {
        return 1; // An empty tree is a valid BST   
    }

    if (curr->data <= min || curr->data >= max)
    {
        return 0; // return false if the current node's value is not within the valid range
    }

    return isValidBSTUtil(curr->left, min, curr->data) && isValidBSTUtil(curr->right, curr->data, max);
}


// Level order traversal of the BST
void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    int queue[100], front = 0, rear = 0;
    queue[rear++] = root->data;

    while (front < rear)  // while the queue is not empty
    {
        int current = queue[front++];
        printf("%d ", current);

        if (root->left != NULL)
        {
            queue[rear++] = root->left->data;
        }

        if (root->right != NULL)
        {
            queue[rear++] = root->right->data;
        }
    }   
}



int main()
{
    struct Node *root = NULL;
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values to insert into the BST:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nIn-order Traversal: ");
    inorderTraversal(root);
    search(12, root);
    printf("\nHeight of the BST: %d\n", height(root));
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);

    if (isValidBST(root))
    {
        printf("\n\nThe given tree is a valid BST.\n");
    }
    else
    {
        printf("\n\nThe given tree is not a valid BST.\n");
    }

    return 0;
}

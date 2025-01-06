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
        return 0;
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




// Boundary Traversal BST
void printLeftBoundary(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left)
    {
        printf("%d ", root->data);
        printLeftBoundary(root->left);
    }
    else if (root->right)
    {
        printf("%d ", root->data);
        printLeftBoundary(root->right);
    }
}

void printRightBoundary(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->right)
    {
        printRightBoundary(root->right);
        printf("%d ", root->data);
    }
    else if (root->left)
    {
        printRightBoundary(root->left);
        printf("%d ", root->data);
    }
}

void printLeaves(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printLeaves(root->left);

    if (root->left == NULL && root->right == NULL)
    {
        printf("%d ", root->data);
    }

    printLeaves(root->right);
}

void BSTBoundaryTraversal(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("\nBoundary Traversal of the BST:\n");
    printf("%d ", root->data);

    printLeftBoundary(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printRightBoundary(root->right);
}

//  Lowest Common Ancestors
struct Node *LCA(struct Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data > n1 && root->data > n2)
    {
        return LCA(root->left, n1, n2);
    }

    if (root->data < n1 && root->data < n2)
    {
        return LCA(root->right, n1, n2);
    }

    return root;
}

// Function to check if the given trees are mirror images of each other
int isMirror(struct Node *root1, struct Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }

    return (root1->data == root2->data) && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}

// Tree from left view
void leftView(struct Node *root, int level, int *maxLevel)
{
    if (root == NULL)
    {
        return;
    }

    if (*maxLevel < level)
    {
        printf("%d ", root->data);
        *maxLevel = level;
    }

    leftView(root->left, level + 1, maxLevel);
    leftView(root->right, level + 1, maxLevel);
}


main()
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

    // Boundary Traversal of the BST
    BSTBoundaryTraversal(root);

    // Lowest Common Ancestor
    struct Node *lca = LCA(root, 10, 15);
    printf("\n\nLowest Common Ancestor of 10 and 15: %d\n", lca->data);

    // validate mirrored trees or not
    struct Node *root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    struct Node *root2 = createNode(1);
    root2->left = createNode(3);
    root2->right = createNode(2);
    root2->right->left = createNode(5);
    root2->right->right = createNode(4);

    if (isMirror(root1, root2)){
        printf("The trees are mirror images of each other.\n");
    }
    else{
        printf("The trees are not mirror images of each other.\n");
    }

    // Tree from left View
    int maxLevel = 0;
    printf("\nLeft View of the BST: ");
    leftView(root, 1, &maxLevel);


    return 0;
}

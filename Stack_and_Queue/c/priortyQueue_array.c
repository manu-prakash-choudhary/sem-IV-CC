#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

// Structure for Max-Heap
typedef struct
{
    int data[MAX_HEAP_SIZE];
    int size;
} MaxHeap;

// Function to initialize the max-heap
void initHeap(MaxHeap *heap)
{
    heap->size = 0;
}

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain max-heap property
void heapify(MaxHeap *heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->data[left] > heap->data[largest])
        largest = left;

    if (right < heap->size && heap->data[right] > heap->data[largest])
        largest = right;

    if (largest != i)
    {
        swap(&heap->data[i], &heap->data[largest]);
        heapify(heap, largest);
    }
}

// Function to insert an element into the max-heap
void insertHeap(MaxHeap *heap, int value)
{
    if (heap->size == MAX_HEAP_SIZE)
    {
        printf("Heap overflow\n");
        exit(EXIT_FAILURE);
    }

    heap->data[heap->size] = value;
    int i = heap->size;
    heap->size++;

    // Fix the max-heap property
    while (i != 0 && heap->data[(i - 1) / 2] < heap->data[i])
    {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the maximum element from the heap
int extractMax(MaxHeap *heap)
{
    if (heap->size <= 0)
    {
        printf("Heap underflow\n");
        exit(EXIT_FAILURE);
    }

    if (heap->size == 1)
    {
        heap->size--;
        return heap->data[0];
    }

    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// Function to find the product of the three largest distinct elements
int findProductOfThreeLargest(int arr[], int n)
{
    MaxHeap heap;
    initHeap(&heap);

    // Insert all elements into the max-heap
    for (int i = 0; i < n; i++)
    {
        insertHeap(&heap, arr[i]);
    }

    int largest = extractMax(&heap);
    int secondLargest = -1, thirdLargest = -1;

    // Find the second largest distinct element
    while (heap.size > 0)
    {
        int next = extractMax(&heap);
        if (next != largest)
        {
            secondLargest = next;
            break;
        }
    }

    // Find the third largest distinct element
    while (heap.size > 0)
    {
        int next = extractMax(&heap);
        if (next != largest && next != secondLargest)
        {
            thirdLargest = next;
            break;
        }
    }

    if (secondLargest == -1 || thirdLargest == -1)
    {
        printf("Not enough distinct elements to find the product\n");
        exit(EXIT_FAILURE);
    }

    return largest * secondLargest * thirdLargest;
}

// Driver function
int main()
{
    int arr[] = {10, 20, 20, 30, 40, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    int product = findProductOfThreeLargest(arr, n);
    printf("The product of the three largest distinct elements is: %d\n", product);

    return 0;
}

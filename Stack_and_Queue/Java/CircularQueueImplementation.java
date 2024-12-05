import java.util.Scanner;

class CircularQueue {
    private int[] queue;
    private int front, rear, size, capacity;

    // Constructor to initialize the circular queue
    public CircularQueue(int capacity) {
        this.capacity = capacity;
        this.queue = new int[capacity];
        this.front = -1;
        this.rear = -1;
        this.size = 0;
    }

    // Function to add an element to the queue
    public void enqueue(int value) {
        if (isFull()) {
            System.out.println("Queue is full! Cannot enqueue.");
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
    }

    // Function to remove an element from the queue
    public void dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty! Cannot dequeue.");
            return;
        }
        System.out.println("Dequeued: " + queue[front]);
        front = (front + 1) % capacity;
        size--;
        if (size == 0) { // Reset pointers if the queue becomes empty
            front = -1;
            rear = -1;
        }
    }

    // Function to get the front element of the queue
    public int front() {
        if (isEmpty()) {
            System.out.println("Queue is empty! No front element.");
            return -1;
        }
        return queue[front];
    }

    // Function to get the rear element of the queue
    public int rear() {
        if (isEmpty()) {
            System.out.println("Queue is empty! No rear element.");
            return -1;
        }
        return queue[rear];
    }

    // Function to display all elements in the queue
    public void display() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return;
        }
        System.out.println("Queue elements:");
        for (int i = 0; i < size; i++) {
            System.out.print(queue[(front + i) % capacity] + " ");
        }
        System.out.println();
    }

    // Check if the queue is full
    private boolean isFull() {
        return size == capacity;
    }

    // Check if the queue is empty
    private boolean isEmpty() {
        return size == 0;
    }
}

public class CircularQueueImplementation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the capacity of the circular queue: ");
        int capacity = sc.nextInt();
        CircularQueue circularQueue = new CircularQueue(capacity);

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Enqueue");
            System.out.println("2. Dequeue");
            System.out.println("3. Front");
            System.out.println("4. Rear");
            System.out.println("5. Display");
            System.out.println("6. Exit");
            System.out.print("Choose an option: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to enqueue: ");
                    int value = sc.nextInt();
                    circularQueue.enqueue(value);
                    break;
                case 2:
                    circularQueue.dequeue();
                    break;
                case 3:
                    int front = circularQueue.front();
                    if (front != -1) {
                        System.out.println("Front element: " + front);
                    }
                    break;
                case 4:
                    int rear = circularQueue.rear();
                    if (rear != -1) {
                        System.out.println("Rear element: " + rear);
                    }
                    break;
                case 5:
                    circularQueue.display();
                    break;
                case 6:
                    System.out.println("Exiting...");
                    sc.close();
                    return;
                default:
                    System.out.println("Invalid choice! Please try again.");
            }
        }
    }
}

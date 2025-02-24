import java.util.LinkedList;

public class HashTable {
    private static final int TABLE_SIZE = 10; // Size of the hash table
    private LinkedList<Integer>[] table; // Array of linked lists

    // Constructor to initialize the hash table
    public HashTable() {
        table = new LinkedList[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = new LinkedList<>(); // Initialize each index with an empty list
        }
    }

    // Hash function: Computes index using modulus
    private int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Insert a key into the hash table
    public void insert(int key) {
        int index = hashFunction(key);
        table[index].add(key); // Add key to the linked list at the computed index
    }

    // Search for a key in the hash table
    public boolean search(int key) {
        int index = hashFunction(key);
        return table[index].contains(key);
    }

    // Delete a key from the hash table
    public void delete(int key) {
        int index = hashFunction(key);
        if (table[index].contains(key)) {
            table[index].remove(Integer.valueOf(key));
            System.out.println("Key " + key + " deleted successfully.");
        } else {
            System.out.println("Key " + key + " not found.");
        }
    }

    // Display the hash table
    public void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            System.out.print("Index " + i + ": " + table[i] + "\n");
        }
    }

    // Main function to test the hash table
    public static void main(String[] args) {
        HashTable hashTable = new HashTable();

        // Insert values
        hashTable.insert(10);
        hashTable.insert(20);
        hashTable.insert(15);
        hashTable.insert(25);
        hashTable.insert(30);

        // Display hash table
        System.out.println("Hash Table before deletion:");
        hashTable.display();

        // Search for a key
        int key = 20;
        if (hashTable.search(key)) {
            System.out.println("Key " + key + " found in hash table.");
        } else {
            System.out.println("Key " + key + " not found in hash table.");
        }

        // Delete a key
        hashTable.delete(20);
        hashTable.delete(50);  // Non-existent key

        // Display after deletion
        System.out.println("Hash Table after deletion:");
        hashTable.display();
    }
}

class TrieNode {
    TrieNode[] children;
    boolean isEndOfWord;

    // Constructor
    public TrieNode() {
        children = new TrieNode[26]; // 26 lowercase English letters
        isEndOfWord = false;
    }
}

public class Trie {
    private TrieNode root;

    // Constructor: Initialize the Trie
    public Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    public void insert(String word) {
        TrieNode current = root;
        for (char ch : word.toCharArray()) {
            int index = ch - 'a';
            if (current.children[index] == null) {
                current.children[index] = new TrieNode();
            }
            current = current.children[index];
        }
        current.isEndOfWord = true;
    }

    // Search for a word in the Trie
    public boolean search(String word) {
        TrieNode current = root;
        for (char ch : word.toCharArray()) {
            int index = ch - 'a';
            if (current.children[index] == null) {
                return false;
            }
            current = current.children[index];
        }
        return current.isEndOfWord;
    }

    // Helper function to check if a node has children
    private boolean hasChildren(TrieNode node) {
        for (TrieNode child : node.children) {
            if (child != null) return true;
        }
        return false;
    }

    // Remove a word from the Trie
    public boolean remove(String word) {
        return removeHelper(root, word, 0);
    }

    private boolean removeHelper(TrieNode current, String word, int depth) {
        if (current == null) return false;

        if (depth == word.length()) {
            if (!current.isEndOfWord) return false; // Word doesn't exist
            current.isEndOfWord = false;
            return !hasChildren(current); // Delete node if no children
        }

        int index = word.charAt(depth) - 'a';
        if (removeHelper(current.children[index], word, depth + 1)) {
            current.children[index] = null;
            return !current.isEndOfWord && !hasChildren(current);
        }
        return false;
    }

    // Main method to test Trie operations
    public static void main(String[] args) {
        Trie trie = new Trie();

        // Insert words
        trie.insert("apple");
        trie.insert("banana");
        trie.insert("bat");
        trie.insert("ball");

        // Search words
        System.out.println("Search apple: " + (trie.search("apple") ? "Found" : "Not Found"));
        System.out.println("Search bat: " + (trie.search("bat") ? "Found" : "Not Found"));
        System.out.println("Search ball: " + (trie.search("ball") ? "Found" : "Not Found"));
        System.out.println("Search cat: " + (trie.search("cat") ? "Found" : "Not Found"));

        // Remove a word
        System.out.println("\nRemoving 'bat'");
        trie.remove("bat");
        System.out.println("Search bat: " + (trie.search("bat") ? "Found" : "Not Found"));
    }
}

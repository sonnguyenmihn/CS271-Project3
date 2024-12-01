//=========================================================
// HashMapTree.cpp
// Son, Omar, Esther
// Nov, 2024
// This is the implementation file for the HashMapTree class with methods:
// Constructors and Destructor, Insert, Assignment Operator, Remove,
// Accessing Operator, Search.
//=========================================================

#include "HashMapTree.hpp"
#include "RBTree.hpp"
#include "RBTreeNode.hpp"
using namespace std;




//=========================================================
// Default constructor for HashMapTree.
// Initializes the hash map with a default size of 100 and prepares 
// the hash function and table.
// Parameters:
//  None
// Returns:
//  None
//=========================================================
template<class K, class V>
HashMapTree<K, V>::HashMapTree() : size(100), numberOfElements(0), hashFn(), table(100) {}


//=========================================================
// Parameterized constructor for HashMapTree.
// Initializes the hash map with the specified size.
// The length should be less than 100001
// Parameters:
//  length: The desired number of slots (buckets) in the hash map.
// Returns:
//  None
//=========================================================
template<class K, class V>
HashMapTree<K, V>::HashMapTree(long length) : size(length), numberOfElements(0), hashFn(), table(length) {}


//=========================================================
// Copy constructor for HashMapTree.
// Copies the contents of another HashMapTree into this instance.
// Parameters:
//  copy: The HashMapTree to copy from.
// Returns:
//  None
//=========================================================
template<class K, class V>
HashMapTree<K, V>::HashMapTree(const HashMapTree& copy) {
    *this = copy;
}


//=========================================================
// Destructor for HashMapTree.
// Performs cleanup if necessary (handled automatically)
// Parameters:
//  None
// Returns:
//  None
//=========================================================
template<class K, class V>
HashMapTree<K, V>::~HashMapTree() {
    return;
}


//=========================================================
// Assignment operator for HashMapTree.
// Deep copy the contents of another HashMapTree into this instance.
// Parameters:
//  copy: The HashMapTree to copy from.
// Returns:
//  Reference to the current HashMapTree after assignment.
//=========================================================
template<class K, class V>
HashMapTree<K, V>& HashMapTree<K, V>::operator=(const HashMapTree<K, V>& copy) {
    if (this != &copy) {
        size = copy.size;
        numberOfElements = copy.numberOfElements;
        hashFn = copy.hashFn;
        table = copy.table;
    }
    return *this;
}


//=========================================================
// Inserts a key-value pair into the hash map.
// Updates the value if the key already exists.
// Parameters:
//  key: The key to insert or update.
//  value: The value associated with the key.
// Returns:
//  None
//=========================================================
template<class K, class V>
void HashMapTree<K, V>::insert(const K& key, const V& value) {
    pair<K, V>* ptr = search(key);
    if (ptr != nullptr) {
        ptr->second = value;
    }
    else {
        long hashVal = hashFn.getHash(key) % size;
        pair<K, V> p = make_pair(key, value);
        table[hashVal].insert(p);
        numberOfElements++;
    }
}


//=========================================================
// Removes a specific key-value pair from the hash map.
// Parameters:
//  item: A pointer to the node containing the pair to remove.
// Returns:
//  None
//=========================================================
template<class K, class V>
void HashMapTree<K, V>::remove(RBTreeNode<pair<K, V>>* item) {
    long hashVal = hashFn.getHash(item->val.first) % size;
    table[hashVal].remove(item);
    numberOfElements--;
}


//=========================================================
// Accesses the value associated with a key in the hash map.
// If the key does not exist, throws an exception.
// Parameters:
//  key: The key to find in the hash map.
// Returns:
//  Reference to the value associated with the key.
//=========================================================
template<class K, class V>
V& HashMapTree<K, V>::operator[](const K& key) {
    pair<K, V>* ptr = search(key);
    if ( ptr == nullptr) {
        throw out_of_range("Key not found in the hash table");
    }
    else {
        return ptr->second;
    }
}


//=========================================================
// Searches for a key in the hash map.
// Parameters:
//  key: The key to search for.
// Returns:
//  Pointer to the pair containing the key and value, or nullptr if not found.
//=========================================================
template<class K, class V>
pair<K, V>* HashMapTree<K, V>::search(const K& key) {

    long hashVal = hashFn.getHash(key) % size;
    RBTreeNode<pair<K, V>>* current = table[hashVal].root;

    while (current != nullptr) {
        if (current->val.first == key) {
            return &(current->val);
        }
        if (current->val.first < key) {
            current = current->right;
        }
        else { 
            current = current->left;
        }
    }
    return nullptr;
}
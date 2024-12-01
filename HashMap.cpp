//=========================================================
// HashMapTree.hpp
// Son, Omar, Esther
// Nov, 2024
// This is the implementation file for the HashMap class.
//Implementation is done with Vectors, we didn't use 
// doubly linked lists
//=========================================================

#include "HashMap.hpp"
#include "customexceptions.hpp"


using namespace std;

//=========================================================
// Constructor for HashMap.
// Initializes the hash map with a specified table size.
// Parameters:
//  size: The initial size of the hash table (default: 100).
// Returns:
//  None
//=========================================================
template <typename K, typename V>
HashMap<K, V>::HashMap(size_t size)
    : tableSize(size), numElements(0), table(size) {}



//=========================================================
// Destructor for HashMap.
// Automatically handles cleanup for the hash map.
// Parameters:
//  None
// Returns:
//  None
//=========================================================
template <typename K, typename V>
HashMap<K, V>::~HashMap() = default;


//=========================================================
// Inserts a key-value pair into the hash map.
// If the key already exists, updates its value.
// Parameters:
//  key: The key to insert or update.
//  value: The value to associate with the key.
// Returns:
//  None
//=========================================================
template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value) {
    size_t index = hashFunction(key) % tableSize;
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            pair.second = value;
            return;
        }
    }
    table[index].emplace_back(key, value);
    ++numElements;
}


//=========================================================
// Removes a key-value pair from the hash map.
// Parameters:
//  deleted: A pointer to the pair to be removed.
// Returns:
//  None
// Throws:
//  Undefined behavior if `deleted` does not point to an element
//  in the correct bucket or is invalid.
//=========================================================
template <typename K, typename V>
void HashMap<K, V>::remove(const K& key) {
    size_t index = hashFunction(key) % tableSize;

    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == key) {
            table[index].erase(it);
            --numElements;
            return;
        }
    }
    throw invalid_argument("Key not found");
}



//=========================================================
// Accesses the value associated with a key in the hash map.
// Throws an exception if the key is not found.
// Parameters:
//  key: The key to look up in the hash map.
// Returns:
//  A reference to the value associated with the key.
// Throws:
//  invalid_argument exception if the key does not exist in the map.
//=========================================================
template <typename K, typename V>
V& HashMap<K, V>::operator[](const K& key) {
    size_t index = hashFunction(key) % tableSize;
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            return pair.second;
        }
    }
    throw invalid_argument("Key not found");
}


//=========================================================
// Searches for a key in the hash map.
// Parameters:
//  key: The key to search for.
// Returns:
//  A pointer to the key-value pair if found, or nullptr if not found.
//=========================================================
template <typename K, typename V>
pair<K, V>* HashMap<K, V>::search(const K& key) {
    size_t index = hashFunction(key) % tableSize;
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            return &pair;
        }
    }
    return nullptr;
}
// Explicit template instantiations
template class HashMap<int, string>;
template class HashMap<int, int>;
template class HashMap<string, string>;
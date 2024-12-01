#include "HashMap.hpp"

template <typename K, typename V>
HashMap<K, V>::HashMap(size_t size)
    : tableSize(size), numElements(0), hashFunction(size), table(size) {
        
    }

template <typename K, typename V>
HashMap<K, V>::~HashMap() = default;

template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value) {
    size_t index = hashFunction.getHash(key);
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            pair.second = value;
            return;
        }
    }
    table[index].emplace_back(key, value);
    ++numElements;
}

template <typename K, typename V>
void HashMap<K, V>::remove(const K& key) {
    size_t index = hashFunction.getHash(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == key) {
            table[index].erase(it);
            --numElements;
            return;
        }
    }
    throw invalid_argument("Key not found");
}

template <typename K, typename V>
V& HashMap<K, V>::operator[](const K& key) {
    size_t index = hashFunction.getHash(key);
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            return pair.second;
        }
    }
    throw invalid_argument("Key not found");
}

template <typename K, typename V>
pair<K, V>* HashMap<K, V>::search(const K& key) {
    size_t index = hashFunction.getHash(key);
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            return &pair;
        }
    }
    return nullptr;
}

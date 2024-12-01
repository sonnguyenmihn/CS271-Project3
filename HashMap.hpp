//=========================================================
// HashMapTree.hpp
// Son, Omar, Esther
// Nov, 2024
// This is the header file with definitions of functions for the HashMap class.
//=========================================================

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <vector>
#include <list>
#include <utility>
#include <stdexcept>
#include "MyHashFunction.hpp"

using namespace std;

template <typename K, typename V>
class HashMap {
public:
    explicit HashMap(size_t size = 100);
    ~HashMap();

    void insert(const K& key, const V& value);
    void remove(const pair<K, V>* deleted);
    V& operator[](const K& key);
    pair<K, V>* search(const K& key);

private:
    size_t tableSize;
    size_t numElements;
    CustomHashFunction<K> hashFunction;
    vector<vector<pair<K, V>>> table;
};

#endif

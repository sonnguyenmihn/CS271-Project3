//=========================================================
// HashMapTree.hpp
// Son, Omar, Esther
// Nov, 2024
// This is the header file with definitions of functions for the HashMap class.
/*
For the implementation of HashMap, we use Vectors.
*/
//=========================================================

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <vector> //outer container
#include <list> //inner container
#include <utility> //store key value-pair in the hash table
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
    MyHashFunction<K> hashFunction;
    vector<vector<pair<K, V>>> table; //table
};

#endif

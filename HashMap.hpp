//=========================================================
// HashMap.hpp
// Son, Omar, Esther
// Nov, 2024
// This is the header file with definitions of functions for the HashMap class.
//=========================================================

#ifndef HASHMAP_HPP
#define HASPMAP_HPP

#include "MyHashFunction.hpp"
#include <vector>
#include <utility>

template <class K, class V>
class HashMap
{
public:
    // Constructor and Destructor
    HashMap();
    HashMap(long length);
    HashMap(const HashMap<K, V> &copy);
    ~HashMap();

    // Methods
    HashMap<K, V> &operator=(const HashMap<K, V> &copy);
    void insert(const K &key, const V &value);
    void remove(pair<K, V> *item);
    V &operator[](const K &key);
    std::pair<K, V> *search(const K &key);
    MyHashFunction<K> hashFn;
    long size;
    std::vector<std::vector<std::pair<K, V>>> table;

private:
    long numberOfElements;
};

#include "HashMap.cpp"
#endif
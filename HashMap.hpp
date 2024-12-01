#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <vector>
#include <stdexcept>
#include <functional>

using namespace std;

template <typename K, typename V>
class HashMap {
public:
    explicit HashMap(size_t size = 100);
    ~HashMap();

    void insert(const K& key, const V& value);
    void remove(const K& key);
    V& operator[](const K& key);
    pair<K, V>* search(const K& key);

private:
    size_t tableSize;
    size_t numElements;
    vector<vector<pair<K, V>>> table;
    hash<K> hashFunction; 
};

#endif

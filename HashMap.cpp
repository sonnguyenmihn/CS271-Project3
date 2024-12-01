//=========================================================
// HashMap.hpp
// Son, Omar, Esther
// Nov, 2024
// This is the implementation file for the HashMap class with functions:
// Constructors and Destructor, Assignment Operator, Insert, Remove, Accessing Operator
// Search
//=========================================================
#include "HashMap.hpp"
#include <utility>

using namespace std;



template<class K, class V>
HashMap<K, V>::HashMap() : size(100), numberOfElements(0), table(100), hashFn() {}



template<class K, class V>
HashMap<K, V>::HashMap(long length) : size(length), numberOfElements(0), table(length), hashFn() {}



template<class K, class V>
HashMap<K, V>::HashMap(const HashMap<K ,V>& copy) {
    *this = copy;
}



template<class K, class V>
HashMap<K, V>::~HashMap() {
    return ;
}


template<class K, class V>
HashMap<K, V>& HashMap<K, V>::operator=(const HashMap<K, V>& copy) {
    if (this != &copy) {
        size = copy.size;
        numberOfElements = copy.numberOfElements;
        hashFn = copy.hashFn;
        table = copy.table;
    }
    return *this;
}


template<class K, class V>
void HashMap<K, V>::insert(const K& key, const V& value) {
    pair<K, V>* ptr = search(key);

    if (ptr != nullptr) {
        ptr->second = value;
    }
    else {
        long hashVal = hashFn.getHash(key) % size;
        pair<K, V> p = make_pair(key, value);
        table[hashVal].push_back(p);
        numberOfElements++;
    }
}



template<class K, class V>
void HashMap<K, V>::remove(pair<K, V>* item) {
    
}


template<class K, class V>
V& HashMap<K, V>::operator[](const K& key) {

}


template<class K, class V>
pair<K, V>* HashMap<K, V>::search(const K& key) {

}
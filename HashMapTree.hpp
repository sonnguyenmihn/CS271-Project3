//=========================================================
// HashMapTree.hpp
// Son, Omar, Esther
// Nov, 2024
// This is the header file with definitions of functions for the HashMapTree class.
//=========================================================

#ifndef HASHMAPTREE_HPP
#define HASHMAPTREE_HPP

#include "RBTree.hpp"
#include "RBTreeNode.hpp"
#include "MyHashFunction.hpp"
#include <vector>
#include <utility>

template <class K, class V>
class HashMapTree
{
public:
    // Constructor and Destructor
    HashMapTree();
    HashMapTree(long length);
    HashMapTree(const HashMapTree<K, V> &copy);
    ~HashMapTree();

    // Methods
    HashMapTree<K, V> &operator=(const HashMapTree<K, V> &copy);
    void insert(const K &key, const V &value);
    void remove(RBTreeNode<pair<K, V>> *item);
    V &operator[](const K &key);
    std::pair<K, V> *search(const K &key);
    MyHashFunction<K> hashFn;
    long size;
    std::vector<RBTree<std::pair<K, V>>> table;

private:
    long numberOfElements;
};

#include "HashMapTree.cpp"
#endif
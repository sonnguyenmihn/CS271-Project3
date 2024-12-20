//=========================================================
// HashMapTree.hpp
// Son, Omar, Esther
// Nov, 2024
// This is the header file with definitions of functions for the Set class.
//=========================================================
#ifndef Set_hpp
#define Set_hpp

#include <iostream>
#include "RBTree.hpp"
#include "RBTreeNode.hpp"

using namespace std;

template <class T>
class Set {
private:
    RBTree<int> RBT;
    
public:
    //Constructors and Destructor
    Set();
    Set(const Set& s);
    ~Set();

    //Functions
    void insert(const T &value);
    void remove(const T &value);
    bool search(const T &value);

    //Helper Functions
    void printSet();
};

#endif

//=========================================================
// Set.cpp
// Son, Omar, Esther
// Dec 2024
// This is the implementation file for the Set Class
// Implementation done using Red Black Trees
//=========================================================
#include <iostream>
#include "Set.hpp"
#include "customexceptions.hpp"

using namespace std;

//=========================================================
// Constructor for Set
// Intializes an empty set
// Parameters:
//   None
// Returns:
//   None
//=========================================================
template<class T>
Set<T>::Set(){
    RBT.root = NULL;
    RBT.size = 0;
}

//=========================================================
// Copy Constructor for Set
// Intializes a set based off a previously existing set
// Parameters:
//    Set to be copied S
// Returns:
//    None
//=========================================================
template<class T>
Set<T>::Set(const Set& s){
    RBT.root = s.root;
    RBT.size = s.size;
}

//=========================================================
// Destructor for Set
// Utilizes the Red Black Tree destructor to handle clean up
// for set
// Paramerers:
//   None
// Returns:
//   None
//=========================================================
template<class T>
Set<T>::~Set(){
    delete RBT.root;
}
//=========================================================
// Inserts a pointer with a value into the Set
// If the value already exists returns with a coustom exception
// Parameters:
//   value: pointer value to be inserted
// Returns:
//   None
//=========================================================
template<class T>
void Set<T>::insert(const T &value) {
    if (search(value) == false) {
        RBT.insert(value);
    }
    else  if (search(value) == true) {
        return;
    }
}

//=========================================================
// Removes a pointer to a value from the Set
// If value does not exist returns a coustom exception
// Parameters:
//    value: pointer to the value to be deleted
// Returns:
//    None
//=========================================================
template<class T>
void Set<T>::remove(const T &value) {
    
    if (search(value) == true) {
        RBT.remove(value);
    }

    throw invalid_argument("Value not found");
}

//=========================================================
// Searches for a value in the set
// If value is found returns true and if not found returns false
// Parameters:
//    value: Value to be searched for
// Returns:
//    None
//=========================================================
template<class T>
bool Set<T>::search(const T &value) {
    if (RBT.search(value) != nullptr ) {
        return true;
    }

    else if (RBT.search(value) = nullptr){
        return false;
    }
}

//=========================================================
// Prints the set in pre-order
// Parameters:
//    None
// Returns:
//    None
//=========================================================
template<class T>
void Set<T>::printSet() {
    RBT.printPreOrderTraversal();
}

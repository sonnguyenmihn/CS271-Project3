//=========================================================
// MyHashFunction.cpp
// Son, Omar, Esther
// Nov, 2024
// This is the implementation file for the MyHashFunction class with functions:
// Constructors, getHash.
// This class selects a hash function from a family (family based on number theory).
//=========================================================

#include "MyHashFunction.hpp"
#include <iostream>
#include <functional>

using namespace std;


//=========================================================
// Default constructor initializes the hash function parameters 
// p`, `a`, and `b` with random values.
// Parameters:
//  None.
// Returns:
//  None.
//=========================================================
template<class T>
MyHashFunction<T>::MyHashFunction() {
    // Initialize p, a, b with appropriate values
    p = 100001; 
    a = 1 + (rand() % (p - 1)); 
    b = rand() % p; 
}


//=========================================================
// Copy constructor copies the hash function parameters from 
// an existing MyHashFunction object.
// Parameters:
//  copy: The MyHashFunction object to copy from.
// Returns:
//  None.
//=========================================================
template<class T>
MyHashFunction<T>::MyHashFunction(const MyHashFunction& copy) {
    p = copy.p;
    a = copy.a;
    b = copy.b;
}


//=========================================================
// Destructor for MyHashFunction
// Parameters:
//  None.
// Returns:
//  None.
//=========================================================
template<class T>
MyHashFunction<T>::~MyHashFunction() {
    return;
}


//=========================================================
// Computes the hash value for a given data object using a 
// randomly chosen hash function.
// Parameters:
//  data: The data object to hash.
// Returns: 
//  The computed hash value (long). Returns -1 on error.
//=========================================================
template<class T> 
long MyHashFunction<T>::getHash(const T& data) {
    try {
        // Convert any datatype into number
        hash<T> defaultHashFn;
        long hashValue = defaultHashFn(data) % p;

        // Compute the hash using random hashing 
        return (a * hashValue + b) % p;
    } catch (const exception &e) {
        cout << "Unhashable type";
        return -1;
    }
}


//=========================================================
// Assignment operator for MyHashFunction
// Parameters:
//  A instance of MyHashFunction class
// Returns:
//  A reference to the current MyHashFunction instance
//=========================================================
template<class T>
MyHashFunction<T>& MyHashFunction<T>::operator=(const MyHashFunction<T> copy) {
    p = copy.p;
    a = copy.a;
    b = copy.b;
    return *this;
}
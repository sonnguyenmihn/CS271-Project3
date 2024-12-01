//=========================================================
// MyHashFunction.hpp
// Son, Omar, Esther
// Nov, 2024
// This is the header file with definitions of functions for the MyHashFunction class.
// This class selects a hash function from a family (family based on number theory).
//=========================================================

#ifndef MYHASHFUNCTION_HPP
#define MYHASHFUNCTION_HPP

template<class T>
class MyHashFunction {
    public:

        // Constructor and Destructor
        MyHashFunction();
        MyHashFunction(const MyHashFunction& copy);
        ~MyHashFunction();

        // Method
        MyHashFunction<T>& operator=(const MyHashFunction<T> copy);
        long getHash(const T& data);

    private:

        // p is prime number, a and b is 2 random numbers less than p, a!= 0
        long p;
        long a;
        long b;
};

#include "MyHashFunction.cpp"
#endif


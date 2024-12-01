//=========================================================
// mytests.cpp
// Son, Omar, Esther
// Nov, 2024
// This is the test file for 3 classes: HashMapTree, HashMap, and Set
//=========================================================
#include "customexceptions.hpp"
#include "HashMapTree.hpp"
#include "HashMap.hpp"
#include <iostream>
#include <string>

using namespace std;

void test_HashMapTree_default_constructor(int &testPassed, int &testFailed);
void test_HashMapTree_parameterized_constructor(int &testPassed, int &testFailed);
void test_HashMapTree_copy_constructor(int &testPassed, int &testFailed);
void test_HashMapTree_assignment_operator(int &testPassed, int &testFailed);
void test_HashMapTree_insert(int &testPassed, int &testFailed);
void test_HashMapTree_remove(int &testPassed, int &testFailed);
void test_HashMapTree_operator_access(int &testPassed, int &testFailed);
void test_HashMapTree_search(int &testPassed, int &testFailed);

int main() {
    int testPassed = 0;
    int testFailed = 0;

    test_HashMapTree_default_constructor(testPassed, testFailed);
    test_HashMapTree_parameterized_constructor(testPassed, testFailed);
    test_HashMapTree_copy_constructor(testPassed, testFailed);
    test_HashMapTree_assignment_operator(testPassed, testFailed);
    test_HashMapTree_insert(testPassed, testFailed);
    test_HashMapTree_remove(testPassed, testFailed);
    test_HashMapTree_operator_access(testPassed, testFailed);
    test_HashMapTree_search(testPassed, testFailed);

    cout << "Total Tests: " << testPassed + testFailed << endl;
    cout << "Tests Passed: " << testPassed << endl;
    cout << "Tests Failed: " << testFailed << endl;

    return 0;
}

//=========================================================
// Test Default Constructor HashMapTree
// Purpose:
//  - Verify that the default constructor initializes with size 100.
//=========================================================
void test_HashMapTree_default_constructor(int &testPassed, int &testFailed) {
    try {
        HashMapTree<int, string> map;
        if (map.search(1) == nullptr) {
            testPassed++;
            cout << "Passed test_HashMapTree_default_constructor" << endl;
        } else {
            testFailed++;
            cout << "Failed test_HashMapTree_default_constructor" << endl;
        }
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_HashMapTree_default_constructor: Exception caught" << endl;
    }
}

//=========================================================
// Test Parameterized Constructor HashMapTree
// Purpose:
//  - Verify that the parameterized constructor initializes correctly.
//=========================================================
void test_HashMapTree_parameterized_constructor(int &testPassed, int &testFailed) {
    try {
        HashMapTree<int, string> map(50);
        if (map.search(1) == nullptr) {
            testPassed++;
            cout << "Passed test_HashMapTree_parameterized_constructor" << endl;
        } else {
            testFailed++;
            cout << "Failed test_HashMapTree_parameterized_constructor" << endl;
        }
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_HashMapTree_parameterized_constructor: Exception caught" << endl;
    }
}

//=========================================================
// Test Copy Constructor HashMapTree
// Purpose:
//  - Verify that the copy constructor performs a deep copy.
//=========================================================
void test_HashMapTree_copy_constructor(int &testPassed, int &testFailed) {
    try {
        HashMapTree<int, string> original;
        original.insert(1, "One");
        HashMapTree<int, string> copy(original);

        if (copy.search(1) != nullptr && copy.search(1)->second == "One") {
            testPassed++;
            cout << "Passed test_HashMapTree_copy_constructor" << endl;
        } else {
            testFailed++;
            cout << "Failed test_HashMapTree_copy_constructor" << endl;
        }
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_HashMapTree_copy_constructor: Exception caught" << endl;
    }
}

//=========================================================
// Test Assignment Operator HashMapTree
// Purpose:
//  - Verify that the assignment operator performs a deep copy.
//=========================================================
void test_HashMapTree_assignment_operator(int &testPassed, int &testFailed) {
    try {
        HashMapTree<int, string> original;
        original.insert(1, "One");
        HashMapTree<int, string> assigned;
        assigned = original;

        if (assigned.search(1) != nullptr && assigned.search(1)->second == "One") {
            testPassed++;
            cout << "Passed test_HashMapTree_assignment_operator" << endl;
        } else {
            testFailed++;
            cout << "Failed test_HashMapTree_assignment_operator" << endl;
        }
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_HashMapTree_assignment_operator: Exception caught" << endl;
    }
}

//=========================================================
// Test Insert HashMapTree
// Purpose:
//  - Verify that values are correctly inserted into the hash map.
//=========================================================
void test_HashMapTree_insert(int &testPassed, int &testFailed) {
    try {
        HashMapTree<int, string> map;
        map.insert(1, "One");
        map.insert(2, "Two");

        if (map.search(1) != nullptr && map.search(1)->second == "One" &&
            map.search(2) != nullptr && map.search(2)->second == "Two") {
            testPassed++;
            cout << "Passed test_HashMapTree_insert" << endl;
        } else {
            testFailed++;
            cout << "Failed test_HashMapTree_insert" << endl;
        }
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_HashMapTree_insert: Exception caught" << endl;
    }
}

//=========================================================
// Test Remove HashMapTree
// Purpose:
//  - Verify that values are correctly removed from the hash map.
//=========================================================
void test_HashMapTree_remove(int &testPassed, int &testFailed) {
    try {
        HashMapTree<int, string> map;
        map.insert(1, "One");
        map.insert(2, "Two");

        pair<int, string>* ptr = map.search(1);
        long hashVal = map.hashFn.getHash(1) % map.size;

        if (ptr != nullptr && map.table[hashVal].root->val.first == 1) {
            map.remove(map.table[hashVal].root);
        }
        else if (map.table[hashVal].root->right) {
          map.remove(map.table[hashVal].root->right);
        }
        else {
          map.remove(map.table[hashVal].root->left);
        }
        if (map.search(1) == nullptr) {
            testPassed++;
            cout << "Passed test_HashMapTree_remove" << endl;
        } else {
            testFailed++;
            cout << "Failed test_HashMapTree_remove" << endl;
        }
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_HashMapTree_remove: Exception caught" << endl;
    }
}

//=========================================================
// Test Operator[] HashMapTree
// Purpose:
//  - Verify that operator[] correctly accesses or updates values.
//=========================================================
void test_HashMapTree_operator_access(int &testPassed, int &testFailed) {
    try {
        HashMapTree<int, string> map;
        map.insert(1, "One");

        if (map[1] == "One") {
            map[1] = "NewOne";
            if (map[1] == "NewOne") {
                testPassed++;
                cout << "Passed test_HashMapTree_operator_access" << endl;
                return;
            }
        }
        testFailed++;
        cout << "Failed test_HashMapTree_operator_access" << endl;
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_HashMapTree_operator_access: Exception caught" << endl;
    }
}

//=========================================================
// Test Search HashMapTree
// Purpose:
//  - Verify that search correctly locates keys in the hash map.
//=========================================================
void test_HashMapTree_search(int &testPassed, int &testFailed) {
    try {
        HashMapTree<int, string> map;
        map.insert(1, "One");
        map.insert(2, "Two");

        if (map.search(1) != nullptr && map.search(1)->second == "One" &&
            map.search(3) == nullptr) {
            testPassed++;
            cout << "Passed test_HashMapTree_search" << endl;
        } else {
            testFailed++;
            cout << "Failed test_HashMapTree_search" << endl;
        }
    } catch (const exception &e) {
        testFailed++;
        cout << "Failed test_HashMapTree_search: Exception caught" << endl;
    }
}


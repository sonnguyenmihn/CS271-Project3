#include <vector>
#include <iostream>
#include <utility>

using namespace std;

int main() {
    vector<pair<int, string>> vec = {{1, "One"}, {2, "Two"}, {3, "Three"}};

    // Pointer pointing to the second pair
    pair<int, string>* ptr = &vec[1];

    // Calculate the iterator to the pair
    auto it = vec.begin() + (ptr - &vec[0]); // Compute iterator from pointer
    cout << ptr << endl;
    // Erase the pair from the vector
    vec.erase(it);

    // Print the updated vector
    for (const auto& p : vec) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
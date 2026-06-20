#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Define a vector of pairs to store int and string
    vector<pair<int, string>> vec;

    // Adding elements to the vector
    vec.push_back(make_pair(1, "Ayush"));
    vec.push_back(make_pair(2, "Neha"));
    vec.push_back(make_pair(3, "Amit"));
    vec.push_back(make_pair(4, "Raj"));
    vec.push_back(make_pair(5, "Nina"));

    // Display the size of the vector
    cout << "Size of the vector: " << vec.size() << endl;

    // Iterating and displaying the elements of the vector
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << "ID: " << it->first << ", Name: " << it->second << endl;
    }

    return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
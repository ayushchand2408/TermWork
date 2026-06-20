#include <iostream>
#include <vector>
#include <cctype> // For tolower
using namespace std;

void displayFreq(const vector<char>& charArray) {
    vector<int> freq(26, 0); 

    for (char ch : charArray) {
        if (isalpha(ch)) { // Ensuring valid characters
            freq[tolower(ch) - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            cout << static_cast<char>('a' + i) << " " << freq[i] << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;
    
    vector<char> charArray;
    char ch;
    
    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++) {
        cin >> ch;
        charArray.push_back(ch);
    }

    displayFreq(charArray);
    
    return 0;
}
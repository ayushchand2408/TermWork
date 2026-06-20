#include<iostream>
using namespace std;

pair<char, int> highest_freq(char arr[], int n) {
    int freq[26] = {0}; 
    
    for(int i = 0; i < n; i++) {
        if (arr[i] >= 'a' && arr[i] <= 'z') {
            freq[arr[i] - 'a']++;
        }
    }
    int max_freq = 0;
    char max_char = 'a';
    for(int i = 0; i < 26; i++) {
        if(freq[i] > max_freq) {
            max_freq = freq[i];
            max_char = 'a' + i;
        }
    }

    return make_pair(max_char, max_freq);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    char arr[n];
    cout << "Enter the elements of the array (a-z): ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<char, int> result = highest_freq(arr, n);
    if(result.second == 1) {
        cout << "No duplicate present" << endl;
    } else {
        cout << "Character with highest frequency: " << result.first << " with frequency: " << result.second << endl;
    }

    return 0;
}

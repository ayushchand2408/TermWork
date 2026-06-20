#include <iostream>
#include <vector>
using namespace std;

bool can(string &s, char start) {
    int n = s.size();
    vector<int> bad;

    for (int i = 0; i < n; i++) {
        char expected = (i % 2 == 0 ? start : (start == 'a' ? 'b' : 'a'));
        if (s[i] != expected) bad.push_back(i);
    }

    if (bad.empty()) return true;

    for (int i = 1; i < bad.size(); i++) {
        if (bad[i] != bad[i - 1] + 1)
            return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        if (can(s, 'a') || can(s, 'b'))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
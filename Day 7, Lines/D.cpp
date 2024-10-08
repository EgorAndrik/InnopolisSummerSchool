#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>

 
using namespace std;


vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    vector<int> z = z_function(s);
    
    int period = n;
    for (int i = 1; i < n; ++i) {
        if (i + z[i] == n && n % i == 0) {
            period = i;
            break;
        }
    }
    
    cout << period << endl;
    return 0;
}
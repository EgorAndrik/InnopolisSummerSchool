#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int n, k;
    cin >> n;
    vector<int> arr_n(n);
    for (int& x : arr_n)
        cin >> x;
    
    sort(arr_n.begin(), arr_n.end());
    
    cin >> k;
    vector<int> res(k);
    
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        
        // смотрит вохождения элементов arr_n в диапазон [l; r]
        auto left = lower_bound(arr_n.begin(), arr_n.end(), l);
        auto right = upper_bound(arr_n.begin(), arr_n.end(), r);
        res[i] = distance(left, right);
    }
    
    for (auto i : res)
        cout << i << ' ';
    
    return 0;
}
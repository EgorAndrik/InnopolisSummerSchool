#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
 
 
using namespace std;
 
int main()
{
    int n, s;
    cin >> n;
    vector<long long> arr(n), res;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> s;
    // sort(arr.begin(), arr.end());
    n--;
    while(s != 0 && n != -1){
        if (s >= arr[n]){
            s -= arr[n] * (s / arr[n]);
            res.push_back(arr[n]);
        }
        n--;
        // cout << s << endl;
    }
    // cout << s << endl;
    if (s == 0){
        cout << res.size() << endl;
        for(auto i : res)
            cout << i << ' ';
    }
    else cout << -1;
}
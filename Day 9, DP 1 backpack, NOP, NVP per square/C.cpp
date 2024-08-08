#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
 
 
using namespace std;
 
int main()
{
    int s, n, mx_m = 0;
    cin >> s >> n;
    vector<int> arr(n), sums_dp;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++){
        int sm = arr[i];
        sums_dp.push_back(arr[i]);
        for(int j = 0; j < n; j++){
            if (j != i){
                sums_dp.push_back(arr[i] + arr[j]);
                sm += arr[j];
                sums_dp.push_back(sm);
            }
            else if (j > 2 && j - 2 != i && j != i){
                sums_dp.push_back(sm - arr[j - 2]);
            }
        }
    }
    sort(sums_dp.begin(), sums_dp.end());
    // for (auto i : sums_dp)
    //     cout << i << ' ';
    // cout << endl;
    for (auto i : sums_dp){
        if (i <= s)
            mx_m = max(mx_m, i);
        else if (i > s)
            break;
    }
    cout << mx_m;
}
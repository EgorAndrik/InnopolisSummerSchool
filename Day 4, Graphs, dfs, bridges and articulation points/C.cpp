#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>


using namespace std;


int main() {
    
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    int j = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            res += arr[i][j];
    cout << res;
    return 0;
}
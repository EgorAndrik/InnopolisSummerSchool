#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>


using namespace std;


int main() {
    int n;
    bool isValid = true;
    cin >> n;
    int res_d2 = 0, res_d1 = 0, res_d_g = 0;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
            if (arr[i][j] != 0 && arr[i][j] != 1)
                isValid = false;
        }
    }
    if (isValid){
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (arr[i][j] != arr[j][i])
                    isValid = false;
                res_d2 += arr[i][j];
                res_d1 += arr[j][i];
            }
            res_d_g += arr[i][i];
        }
        // cout << res_d1 << ' ' << res_d2 << ' ' << res_d_g << endl;
        if (res_d_g == 0 && res_d1 == res_d2 && isValid)
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "NO";
    return 0;
}
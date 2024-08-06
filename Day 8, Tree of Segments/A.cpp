#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>

 
using namespace std;


long long nextPowerOfTwo(unsigned long long n) {
    if (n == 0) return 1;
    double logBase2 = log2(n);
    return static_cast<long long>(pow(2, ceil(logBase2)));
}


void setWL(vector<long long> &arr, long long i, long long x){
    long long tmp = arr[i];
    arr[(i - i % 2) / 2] = arr[(i - i % 2) / 2] - arr[i] + x;
    arr[i] = x;
    for (i /= 2; i >= 1; i /= 2) {
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }
}


long long sumWL(const vector<long long>& arr, long long l, long long r, long long n) {
    l += n / 2;
    r += n / 2;
    long long sum = 0;
    while (l <= r) {
        if (l % 2 == 1) sum += arr[l++];
        if (r % 2 == 0) sum += arr[r--];
        l /= 2;
        r /= 2;
    }
    return sum;
}


int main()
{
    long long n, num;
    cin >> n;
    long long n_arr = nextPowerOfTwo(n) * 2;
    vector<long long> arr(n_arr - 1, 0);
    long long point = n_arr / 2 - 1;
    for(long long i = n_arr / 2; i < n_arr + (n - n_arr / 2); i++){;
        cin >> num;
        setWL(arr, i, num);
    }
    // for (auto i : arr)
    //     cout << i << ' ';
    // cout << endl;
    string command;
    long long i, j, x;
    while(cin >> command){
        if (command == "sum"){
            cin >> i >> j;
            // cout << i << ' ' << j << ' ' << n_arr / 2 + i - 1 << ' ' << n_arr / 2 + j - 1 << endl;
            cout << sumWL(arr, i - 1, j - 1, n_arr) << endl;
        }
        else {
            cin >> i >> x;
            setWL(arr, n_arr / 2 + i - 1, x);
            // for (auto i : arr)
            //     cout << i << ' ';
            // cout << endl;
        }
    }
}
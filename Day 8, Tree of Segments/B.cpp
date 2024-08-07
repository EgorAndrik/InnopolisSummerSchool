#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
long long nextPowerOfTwo(unsigned long long n) {
    if (n == 0) return 1;
    double logBase2 = log2(n);
    return static_cast<long long>(pow(2, ceil(logBase2)));
}
 
 
void setWL(vector<long long>& arr, long long n, long long i, long long x) {
    i += n;
    arr[i] = x;
    for (i /= 2; i >= 1; i /= 2)
        arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
}
 
 
void setWL_rmq2(vector<long long>& arr, long long n, long long i, long long j, long long x) {
    for (long long k = i; k <= j; ++k)
        setWL(arr, n, k, x);
}
 
 
void add_rmq2(vector<long long>& arr, long long n, long long i, long long j, long long x) {
    for (long long k = i; k <= j; ++k) {
        long long idx = k + n;
        arr[idx] += x;
        for (idx /= 2; idx >= 1; idx /= 2)
            arr[idx] = min(arr[idx * 2], arr[idx * 2 + 1]);
    }
}
 
 
long long minWL(const vector<long long>& arr, long long l, long long r, long long n) {
    l += n;
    r += n;
    long long min_n = 1e18;
    while (l <= r) {
        min_n = min(min_n, arr[l++]);
        min_n = min(min_n, arr[r--]);
    }
    return min_n;
}
 
 
int main() {
    long long n, num;
    cin >> n;
    long long n_arr = nextPowerOfTwo(n);
    vector<long long> arr(n_arr * 2, 1e18);
 
    for (long long i = 0; i < n; ++i) {
        cin >> num;
        setWL(arr, n_arr, i, num);
    }
 
    string command;
    long long i, j, x;
    while (cin >> command) {
        if (command == "set") {
            cin >> i >> j >> x;
            setWL_rmq2(arr, n_arr, i - 1, j - 1, x);
        } else if (command == "add") {
            cin >> i >> j >> x;
            add_rmq2(arr, n_arr, i - 1, j - 1, x);
        } else if (command == "min") {
            cin >> i >> j;
            auto min_it = min_element(arr.begin() + (n_arr + (i - 1)), arr.begin() + (n_arr + j));
            cout << *min_it << endl;
        }
    }
 
    return 0;
}
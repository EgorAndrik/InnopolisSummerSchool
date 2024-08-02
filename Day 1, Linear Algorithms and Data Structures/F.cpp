#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && arr[dq.back()] > arr[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            cout << arr[dq.front()] << endl;
    }

    return 0;
}
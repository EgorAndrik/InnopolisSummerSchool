#include <iostream>
#include <vector>
#include <deque>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int el1 = 0, el2 = 1, cnt = 1, result = 0;
    deque<int> arr_el;
    while (true){
        // cout << arr[el1] << " " << arr[el2] << " " << cnt << " " << arr.size() << ' ' << result << endl;
        if (arr[el1] == arr[el2]) {
            cnt++;
            arr_el.push_back(el1);
            el1++;
            el2++;
        }
        else if (cnt >= 3 && arr[el1] != arr[el2]) {
            result += arr_el.size() + 1;
            arr_el.push_back(el1);
            for (int i = arr_el.size() - 1; i >= 0; i--) {
                arr.erase(arr.begin() + arr_el[i]);
            }
            cnt = 1;
            arr_el.clear();
            el1 = 0;
            el2 = 1;
        }
        else {
            cnt = 1;
            arr_el.clear();
            el1++;
            el2++;
        }
        if (el2 >= arr.size())
            break;
    }
    if (cnt >= 3)
        result += cnt;
    cout << endl << result;
    return 0;
}
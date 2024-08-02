#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int num, n;
    cin >> num;
    vector<int> mask(1000001, 0);
    vector<int> arr_ind_mask;
    for (int i = 0; i < num; i++) {
        cin >> n;
        mask[n]++;
        arr_ind_mask.push_back(n);
    }
    for (int el : arr_ind_mask) {
        if (mask[el] % 4 != 0) {
            cout << el;
            break;
        }
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<int> arr;
    int num;
    while (cin >> num)
        arr.push_back(num);
    vector<int> mask(2 * 100000);
    for (int n : arr)
        mask[n]++;
    int ind_arr = 0;
    for (int i = 0; i < mask.size(); i ++){
        while (mask[i] != 0){
            arr[ind_arr] = i;
            ind_arr++;
            mask[i]--;
        }
    }
    for(int n : arr)
        cout << n << ' ';

    return 0;
}
#include <iostream>
#include <vector>


using namespace std;


bool binSearch(vector<int> arr, int elemSearch){
    int left = 0, right = arr.size() - 1, middle;
    while (left <= right){
        middle = (left + right) / 2;
        if (arr[middle] > elemSearch)
            right = middle - 1;
        else if (arr[middle] < elemSearch)
            left = middle + 1;
        else
            return true;
    }
    return false;
}


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr_n(n), arr_k(k);
    for (int i = 0; i < n; i++)
        cin >> arr_n[i];
    for (int i = 0; i < k; i++)
        cin >> arr_k[i];
    for (int num: arr_k){
        if (binSearch(arr_n, num))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

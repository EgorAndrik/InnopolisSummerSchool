#include <iostream>
#include <vector>


using namespace std;


void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r)
        return;
    int middle = (l + r) / 2;
    mergeSort(arr, l, middle);
    mergeSort(arr, middle + 1, r);
    vector<int> arr_tmp(r - l + 1);
    int i = l, j = middle + 1, k = 0;
    while (i <= middle && j <= r) {
        if (arr[i] < arr[j]) {
            arr_tmp[k] = arr[i];
            k++;
            i++;
        } else {
            arr_tmp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= middle) {
        arr_tmp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= r) {
        arr_tmp[k] = arr[j];
        k++;
        j++;
    }
    for (int step = 0; step < r - l + 1; step++)
        arr[l + step] = arr_tmp[step];
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    for (int i : arr)
        cout << i << ' ';
}
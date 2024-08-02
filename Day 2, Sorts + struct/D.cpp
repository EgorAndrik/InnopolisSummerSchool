#include <iostream>
#include <vector>
#include <deque>

using namespace std;


int main()
{
    int n, m;
    
    cin >> n;
    vector<int> arr_n(n);
    for (int i = 0; i < n; i++)
        cin >> arr_n[i];
    
    cin >> m;
    vector<int> arr_m(m);
    for (int i = 0; i < m; i++)
        cin >> arr_m[i];
        
    vector<int> arr_m_n(n + m);
    int step_n = 0, step_m = 0, index_m_n = 0;
    while (step_n < n && step_m < m){
        // cout << step_n << ' ' << step_m << ' ' << index_m_n << ' ' << arr_n[step_n] << ' ' << arr_m[step_m] << endl;
        if (arr_n[step_n] <= arr_m[step_m]){
            arr_m_n[index_m_n] = arr_n[step_n];
            step_n++;
            index_m_n++;
        }
        else if (arr_n[step_n] >= arr_m[step_m]){
            arr_m_n[index_m_n] = arr_m[step_m];
            step_m++;
            index_m_n++;
        }
    }
    while (step_m < m){
        arr_m_n[index_m_n] = arr_m[step_m];
        step_m++;
        index_m_n++;
    }
    while (step_n < n){
        arr_m_n[index_m_n] = arr_n[step_n];
        step_n++;
        index_m_n++;
    }
    for (int n : arr_m_n)
        cout << n << ' ';
    

    return 0;
}
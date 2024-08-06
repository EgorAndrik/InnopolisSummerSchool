#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;


deque<int> p_func(string text, int point, int &cnt){
    vector<int> arr(text.size(), 0);
    deque<int> arr_2;
    int k;
    for(int i = 1; i < text.size(); i++){
        k = arr[i - 1];
        while(text[i] != text[k] && k != 0)
            k = arr[k - 1];
        if (text[i] == text[k])
            arr[i] = k + 1;
        if (arr[i] == point){
            cnt++;
            arr_2.push_back(i - 2 * point + 1);
        }
    }
    return arr_2;
}

 
int main()
{
    string p, t;
    cin >> t >> p;
    string text = t + "#" + p;
    int cnt = 0;
    deque<int> arr = p_func(text, t.size(), cnt);
    cout << cnt << endl;
    for (auto i : arr)
        cout << i << ' ';
    
}
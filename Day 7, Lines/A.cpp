#include <iostream>
#include <string>
#include <vector>


using namespace std;


int main()
{
    string text;
    cin >> text;
    
    vector<int> arr(text.size(), 0);
    int k;
    for(int i = 1; i < text.size(); i++){
        k = arr[i - 1];
        while(text[i] != text[k] && k != 0)
            k = arr[k - 1];
        if (text[i] == text[k])
            arr[i] = k + 1;
    }
    for(auto i : arr)
        cout << i << ' ';
}
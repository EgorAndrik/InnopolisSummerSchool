#include <iostream>
#include <vector>


using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> arr_n(n);
    for (int i = 0; i < n; i++)
        arr_n[i] = i;
    int middle = n / 2;
    int left = 0, right = n;
    cout << arr_n[middle] << endl;
    int command;
    while (true){
        cin >> command;
        if (command == 0)
            break;
        else if (command == 1){
            left = middle;
            middle = (left + right) / 2;
            cout << arr_n[middle] << endl;
        }
        else{
            right = middle;
            middle = (left + right) / 2;
            cout << arr_n[middle] << endl;
        }
    }
    
}

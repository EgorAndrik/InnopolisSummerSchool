#include <iostream>
#include <deque>
#include <vector>


using namespace std;

int main()
{
    vector<deque<int>> deque_arr(150001);
    
    int n;
    string comand;
    int a, b;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> comand;
        cin >> a;
        if (comand == "pushfront"){
            cin >> b;
            deque_arr[a].push_front(b);
        }
        else if(comand == "pushback"){
            cin >> b;
            deque_arr[a].push_back(b);
        }
        else if(comand == "popfront"){
            cout << deque_arr[a].front() << endl;
            deque_arr[a].pop_front();
        }
        else if(comand == "popback"){
            cout << deque_arr[a].back() << endl;
            deque_arr[a].pop_back();
        }
    }
    
}
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> g1;
    int n;
    char comand;
    int num;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> comand;
        if (comand == '+'){
            cin >> num;
            g1.push(num);
        }
        else {
            cout << g1.front() << endl;
            g1.pop();
        }
    }
    
}
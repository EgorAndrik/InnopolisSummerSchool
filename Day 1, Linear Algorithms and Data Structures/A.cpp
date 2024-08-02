#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> g1;
    vector<int> g2;
    int n;
    int comand, num;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> comand;
        if (comand == 1){
            cin >> num;
            g1.push_back(num);
        }
        else{
            num = g1.back();
            g1.pop_back();
            g2.push_back(num);
        }
    }
    for(int n2 : g2)
        cout << n2 << endl;
}
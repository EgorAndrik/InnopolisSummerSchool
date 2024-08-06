#include <iostream>
#include <string>
#include <vector>
 
 
using namespace std;
 
int main()
{
    string text;
    cin >> text;
    int m;
    cin >> m;
    int a, b, c, d;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c >> d;
        if (a == c && b == d)
            cout << "Yes" << endl;
        else if (text.substr(a - 1, b - a + 1) == text.substr(c - 1, d - c + 1))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
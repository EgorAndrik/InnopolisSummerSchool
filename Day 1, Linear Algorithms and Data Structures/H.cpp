#include <iostream>
#include <vector>
#include <deque>
 
using namespace std;
 
int main() {
    string brackets;
    cin >> brackets;
    deque<char> check;
    for(auto el : brackets){
        if (check.empty())
            check.push_back(el);
        else if (check.back() == '(' && el == ')')
            check.pop_back();
        else
            check.push_back(el);
    }
    cout << check.size();
    return 0;
}
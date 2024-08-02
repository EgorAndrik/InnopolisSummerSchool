#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int main() {
    string el;
    double num1, num2;
    deque<string> arr;
    while(cin >> el){
        if (arr.empty())
            arr.push_front(el);
        else {
            if (el == "+"){
                num1 = stoi(arr.front());
                arr.pop_front();
                num2 = stoi(arr.front());
                arr.pop_front();
                arr.push_front(to_string(num2 + num1));
            }
            else if (el == "-"){
                num1 = stoi(arr.front());
                arr.pop_front();
                num2 = stoi(arr.front());
                arr.pop_front();
                arr.push_front(to_string(num2 - num1));
            }
            else if (el == "*"){
                num1 = stoi(arr.front());
                arr.pop_front();
                num2 = stoi(arr.front());
                arr.pop_front();
                arr.push_front(to_string(num2 * num1));
            }
            else {
                arr.push_front(el);
            }
        }
    }
    cout << endl << stoi(arr.front());
}

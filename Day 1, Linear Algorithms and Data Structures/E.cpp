#include <iostream>
#include <vector>
#include <stack>


using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> main_stack;
    stack<int> min_stack;
    
    int command;
    int num;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == 1) {
            cin >> num;
            main_stack.push_back(num);
            if (min_stack.empty() || num <= min_stack.top())
                min_stack.push(num);
        }
        else if (command == 2) {
            if (!main_stack.empty()) {
                if (main_stack.back() == min_stack.top())
                    min_stack.pop();
                main_stack.pop_back();
            }
        }
        else
            cout << min_stack.top() << endl;
    }

    return 0;
}
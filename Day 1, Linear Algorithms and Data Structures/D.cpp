#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>
 
 
using namespace std;
 
int main()
{
    int n, a, b;
    cin >> n;
    deque<int> deque_arr;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        if (i == 0){
            deque_arr.push_back(b);
            deque_arr.push_front(a);
        }
        else {
            if (deque_arr.back() == a)
                deque_arr.push_back(b);
            else if(deque_arr.front() == b)
                deque_arr.push_front(a);
            else {
                auto it = find(deque_arr.begin(), deque_arr.end(), b);
                deque_arr.insert(it, a);
            }
        }
    }
    for(int elem : deque_arr)
        cout << elem << ' ';
}
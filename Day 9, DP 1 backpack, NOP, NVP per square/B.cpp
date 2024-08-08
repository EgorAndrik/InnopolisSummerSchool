#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long num;
    cin >> num;
    const long long INF = 1e18;
    
    vector<long long> steps(num + 1, INF);
    vector<long long> previous(num + 1, -1);
    steps[num] = 0;

    for (long long current = num; current >= 1; --current) {
        if (current % 2 == 0 && steps[current / 2] > steps[current] + 1) {
            steps[current / 2] = steps[current] + 1;
            previous[current / 2] = current;
        }
        if (current % 3 == 0 && steps[current / 3] > steps[current] + 1) {
            steps[current / 3] = steps[current] + 1;
            previous[current / 3] = current;
        }
        if (current - 1 >= 1 && steps[current - 1] > steps[current] + 1) {
            steps[current - 1] = steps[current] + 1;
            previous[current - 1] = current;
        }
    }

    vector<long long> result;
    long long step = 1;
    while (step != -1) {
        result.push_back(step);
        step = previous[step];
    }

    cout << result.size() - 1 << endl;
    for (auto i : result) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}

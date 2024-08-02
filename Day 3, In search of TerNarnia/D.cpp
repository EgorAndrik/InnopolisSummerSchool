#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;


double binSearch(double n){
    double left = 0, right = n, middle, res;
    for (int i = 0; i < 100; i++) {
        middle = (left + right) / 2;
        res = middle * middle + sqrt(middle);
        if (res > n)
            right = middle;
        else
            left = middle;
    }
    return middle;
}


int main() {
    
    double c;
    cin >> c;
    cout << fixed << setprecision(6) << binSearch(c);
    
    return 0;
}
#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;


double f(double x, double a, double b, double c){
    return x * x * a + x * b + c;
}


double threeSearch(double a, double b, double c){
    double left = -2 * 10 * 10, right = 2 * 10 * 10, EPS = 1e-7, middle1, middle2;
    while (right - left > EPS){
        middle1 = left + (right - left) / 3;
        middle2 = right - (right - left) / 3;
        if (f(middle1, a, b, c) < f(middle2, a, b, c))
            right = middle2;
        else if (f(middle1, a, b, c) > f(middle2, a, b, c))
            left = middle1;
        else
            return min(middle1, middle2);
    }
    return min(middle1, middle2);
}


int main() {
    
    double a, b, c;
    cin >> a >> b >> c;
    // cout << fixed << setprecision(6) << (-1 * b) / (2 * a) << endl; // math method
    cout << fixed << setprecision(6) << threeSearch(a, b, c);
    
    return 0;
}
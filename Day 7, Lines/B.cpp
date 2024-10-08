#include <iostream>
#include <string>
#include <vector>
 
 
using namespace std;


vector<int> z_function (string s) {
	int n = s.size();
	vector<int> z (n);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if (i + z[i] - 1 > r){
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

 
int main()
{
    string text;
    cin >> text;
    vector<int> arr = z_function(text);
    for(int i = 1; i < arr.size(); i++)
        cout << arr[i] << ' ';
}
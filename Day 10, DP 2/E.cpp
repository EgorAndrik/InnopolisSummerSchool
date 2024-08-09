#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>


using namespace std;


long long m(char a, char b){
    return (long long) (a != b);
}


long long LevenshteinDistance(
    long long d1, long long d2, long long d3,
    char a, char b)
{
    return min(d1 + 1, min(d2 + 1, d3 + m(a, b)));
}



int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    long long n = str1.size() + 1, m = str2.size() + 1;
    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++)
        dp[i][0] = i;
    for(int i = 0; i < m; i++)
        dp[0][i] = i;
    
    
    // cout << "    ";
    // for(auto j : str2)
    //     cout << j << ' ';
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     if (i - 1 >= 0)
    //         cout << str1[i - 1] << ' ';
    //     else cout << "  ";
    //     if (i < n - 1){
    //         for(int j = 0; j < m; j++)
    //             cout << dp[i][j] << ' ';
    //     }
    //     else{
    //         for(int j = 0; j < m; j++)
    //             cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    for (int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            dp[i][j] = LevenshteinDistance(
                dp[i - 1][j],
                dp[i][j - 1],
                dp[i - 1][j - 1],
                str1[i - 1],
                str2[j - 1]
                );
    
    // cout << endl;
    // cout << "    ";
    // for(auto j : str2)
    //     cout << j << ' ';
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     if (i - 1 >= 0)
    //         cout << str1[i - 1] << ' ';
    //     else cout << "  ";
    //     if (i < n - 1){
    //         for(int j = 0; j < m; j++)
    //             cout << dp[i][j] << ' ';
    //     }
    //     else{
    //         for(int j = 0; j < m; j++)
    //             cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    cout << dp[n - 1][m - 1];
    
}
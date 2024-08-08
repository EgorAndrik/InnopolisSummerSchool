#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>


using namespace std;


int main()
{
    long long n, res = 0;
    cin >> n;
    vector<string> arr(n);
    vector<vector<long long>> dp(n, vector<long long>(3, -1));
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    if (arr[0][0] != 'W' || arr[0][1] != 'W' || arr[0][2] != 'W'){
        if (arr[0][0] == '.') dp[0][0] = 0;
        if (arr[0][1] == '.') dp[0][1] = 0;
        if (arr[0][2] == '.') dp[0][2] = 0;
        
        if (arr[0][0] == 'C') dp[0][0] = 1;
        if (arr[0][1] == 'C') dp[0][1] = 1;
        if (arr[0][2] == 'C') dp[0][2] = 1;
        
        res = max(res, max(dp[0][0], max(dp[0][1], dp[0][2])));
        
        for (int i = 0; i < n - 1; i++){
            if (arr[i + 1][0] != 'W' || arr[i + 1][1] != 'W' || arr[i + 1][2] != 'W'){
                if (dp[i][0] >= 0){
                    if (arr[i + 1][0] == '.')
                        dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
                    else if (arr[i + 1][0] == 'C' && dp[i + 1][0] != dp[i][0] + 1)
                        dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + 1);
                    
                    if (arr[i + 1][1] == '.')
                        dp[i + 1][1] = max(dp[i + 1][1], dp[i][0]);
                    else if (arr[i + 1][1] == 'C' && dp[i + 1][1] != dp[i][0] + 1)
                        dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + 1);
                }
                
                if (dp[i][1] >= 0){
                    if (arr[i + 1][0] == '.')
                        dp[i + 1][0] = max(dp[i + 1][0], dp[i][1]);
                    else if (arr[i + 1][0] == 'C' && dp[i + 1][0] != dp[i][1] + 1)
                        dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + 1);
                    
                    if (arr[i + 1][1] == '.')
                        dp[i + 1][1] = max(dp[i + 1][1], dp[i][1]);
                    else if (arr[i + 1][1] == 'C' && dp[i + 1][1] != dp[i][1] + 1)
                        dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + 1);
                    
                    if (arr[i + 1][2] == '.')
                        dp[i + 1][2] = max(dp[i + 1][2], dp[i][1]);
                    else if (arr[i + 1][2] == 'C' && dp[i + 1][2] != dp[i][1] + 1)
                        dp[i + 1][2] = max(dp[i + 1][2], dp[i][1] + 1);
                }
                
                if (dp[i][2] >= 0){
                    if (arr[i + 1][1] == '.')
                        dp[i + 1][1] = max(dp[i + 1][1], dp[i][2]);
                    else if (arr[i + 1][1] == 'C' && dp[i + 1][1] != dp[i][2] + 1)
                        dp[i + 1][1] = max(dp[i + 1][1], dp[i][2] + 1);
                    
                    if (arr[i + 1][2] == '.')
                        dp[i + 1][2] = max(dp[i + 1][2], dp[i][2]);
                    else if (arr[i + 1][2] == 'C' && dp[i + 1][2] != dp[i][2] + 1)
                        dp[i + 1][2] = max(dp[i + 1][2], dp[i][2] + 1);
                }
                res = max(res, max(dp[i + 1][0], max(dp[i + 1][1], dp[i + 1][2])));
            }
            else break;
        }
        
        // for(auto i : dp){
        //     for(auto j : i)
        //         cout << j << ' ';
        //     cout << endl;
        // }
        
        cout << res << endl;
    }
    else cout << 0;
}
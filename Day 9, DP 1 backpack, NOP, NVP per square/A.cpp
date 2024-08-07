#include <iostream>
#include <string>
#include <vector>
#include <cmath>
 
 
using namespace std;
 
int main()
{
    long long n_cin, k_cin, MOD = 1e9 + 7;
    cin >> n_cin >> k_cin;
    long long cnt = 0, sm, point;
    int step;
    n_cin++;
    k_cin++;
    vector<vector<long long>> dp(k_cin, vector<long long>(n_cin, 0));
    dp[0][0] = 1;
    vector<long long> dp_sums(n_cin, 0);
    dp_sums[0] = 1;
    for(long long n = 1; n < n_cin; n++){
        step = min(n, k_cin - 1);
        
        for(long long k = 1; k <= step; k++)
            dp[k][n] = (dp_sums[n - k] - dp[k][n - k] + MOD) % MOD;
        dp_sums[n] = 0;
        
        for(long long k = 1; k <= step; k++)
            dp_sums[n] = (dp_sums[n] + dp[k][n]) % MOD;
    }
    
    // for (long long i = 1; i < k_cin; i++)
    //     cnt = (cnt + dp[i][n_cin - 1]) % MOD;
    // cout << cnt << endl;
    
    for(int i = n_cin - 1; i >= 0; i--){
        if(dp_sums[i] != 0){
            cout << dp_sums[i] << endl;
            break;
        }
    }
}
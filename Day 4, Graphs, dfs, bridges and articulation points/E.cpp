#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


void dfs(vector<int>& res_data, vector<bool>& visit_data, const vector<vector<int>>& data_g, int ind_d_g, int w)
{
    if (visit_data[ind_d_g])
        return;
    visit_data[ind_d_g] = true;
    res_data[ind_d_g] = w;
    for (auto k : data_g[ind_d_g])
        dfs(res_data, visit_data, data_g, k, w);
    
}


int main()
{
    int n, m, d, e, w = 1, ind_d_g = 0;
    cin >> n >> m;
    vector<vector<int>> data_g(n);
    vector<bool> visit_data(n, false);
    vector<int> res_data(n, 0);
    for(int i = 0; i < m; i++){
        cin >> d >> e;
        data_g[d - 1].push_back(e - 1);
        data_g[e - 1].push_back(d - 1);
    }
    for (int i = 0; i < n; i++){
        if (!visit_data[i]){
            dfs(res_data, visit_data, data_g, i, w);
            w++;
        }
    }
    cout << w - 1 << endl;
    for (auto j : res_data)
        cout << j << ' ';

    return 0;
}
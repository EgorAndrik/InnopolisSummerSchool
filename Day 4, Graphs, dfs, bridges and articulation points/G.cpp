#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
 
 
using namespace std;

 
bool dfs(vector<int>& visited, const vector<vector<int>>& graph, int v) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (visited[to] == 0)
            if (dfs(visited, graph, to))
                return true;
        else if (visited[to] == 1)
            return true;
    }
    visited[v] = 2;
    return false;
}


int dfs_count(vector<int>& visited, const vector<vector<int>>& graph, int v, int& c) {
    visited[v] = 1;
    c++;
    for (int to : graph[v]) {
        if (visited[to] == 0){
            dfs_count(visited, graph, to, c);
        }
    }
    return c;
}


int main()
{
    int n, el, e = 0, c = 0;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<int> visited_count(n, 0);
    vector<int> visited(n, 0);
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> el;
            if (j > i && el == 1){
                graph[i].push_back(j);
                graph[j].push_back(i);
                e++;
            }
        }
    }
    dfs_count(visited_count, graph, 0, c);
    if (c != n){
        cout << "NO";
        return 0;
    }
    
    if (n != e + 1){
        cout << "NO";
        return 0;
    }
    
    if (dfs(visited, graph, 0)){
        cout << "NO";
        return 0;
    }
    
    cout << "YES";
    return 0;
}
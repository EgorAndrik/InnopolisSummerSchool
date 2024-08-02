#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
 
 
using namespace std;
 

deque<int> getCycle(const vector<int>& from, int lastVertex){
    deque<int> cycle = { lastVertex };
    for(int vertex = from[lastVertex];
        vertex != lastVertex;
        vertex = from[vertex])
            cycle.push_front(vertex);
    return cycle;
}

 
bool dfs(vector<int>& visited, const vector<vector<int>>& graph,
    int v, vector<int>& from, deque<int>& cycle) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (visited[to] == 0) {
            from[to] = v;
            if (dfs(visited, graph, to, from, cycle)) {
                return true;
            }
        } else if (visited[to] == 1) {
            from[to] = v;
            cycle = getCycle(from, to);
            return true;
        }
    }
    visited[v] = 2;
    return false;
}

 
int main()
{
    int n, m, e, v;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> visited(n, 0);
    vector<int> from(n, -1);
    deque<int> cycle;
    
    for(int i = 0; i < m; i++){
        cin >> e >> v;
        graph[e - 1].push_back(v - 1);
    }
    
    for (int i = 0; i < n; i ++){
        if (!visited[i] && dfs(visited, graph, i, from, cycle)){
            cout << "YES" << endl;
            for(int vertex : cycle)
                cout << vertex + 1 << " ";
            return 0;
        }
    }
    cout << "NO";
    
    return 0;
}
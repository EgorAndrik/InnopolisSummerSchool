#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
 
 
using namespace std;


const int INF = 1e9;


int bfs(vector<vector<int>> &graph, int start, int finish){
    vector<int> dist(graph.size(), INF);
    queue<int> q;
    
    dist[start] = 0;
    q.push(start);
    int v;
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int to: graph[v]){
            if(dist[to] > dist[v] + 1){
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    if (dist[finish] == INF)
        return 0;
    return dist[finish];
}


int main()
{
    int n, el, s, f;
    cin >> n >> s >> f;
    vector<vector<int>> graph(n);
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> el;
            if (j > i && el == 1){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    cout << bfs(graph, s - 1, f - 1);
    return 0;
}
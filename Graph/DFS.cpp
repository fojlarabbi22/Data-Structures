#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<bool> vis(N, false);
vector<int> level(N);

void dfs(int st, vector<int>* adj) {
    vis[st] = true;
    cout << st << " ";
    for(auto i: adj[st]) {
        if(vis[i] != true) {
            dfs(i, adj);
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;
 
    vector<int> adj[n + 1];
    for(int i = 1; i <= e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, adj);

    
/*     1
      / \
    2     6
   / \   / \
  3   4 7   9
     /   \
    5-----8     */
 
 // 9 9
/*  1 2
    1 6
    2 3
    2 4
    6 7
    6 9
    4 5
    7 8
    5 8  */
 
}

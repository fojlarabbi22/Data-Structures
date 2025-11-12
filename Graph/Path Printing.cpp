#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool vis[N] = {false};
int par[N] = {0};

void bfs(int st, vector<int>* adj) {
    vis[st] = true;
    par[st] = -1;
    queue<int> q;
    q.push(st);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr <<" ";
        for(auto i: adj[curr]) {
            if(vis[i] != true) {
                par[i] = par[curr] + 1;
                vis[i] = true;
                q.push(i);
            }
        }
    }
}
void print_path(node) {
    if(par[node] == -1) {
        cout << node << " ";
        return;
    }
    print_path(par[node]);
    cout << "--> " << node;
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
    bfs(6, adj);
    print_path(8);
   
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

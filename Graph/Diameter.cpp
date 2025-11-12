#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<bool> vis(N, false);
vector<int> level(N);

void bfs(int st, vector<int>* adj) {
    vis[st] = true;
    level[st] = 0;
    queue<int> q;
    q.push(st);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        //cout << curr <<" ";
        for(auto i: adj[curr]) {
            if(vis[i] != true) {
                level[i] = level[curr] + 1;
                vis[i] = true;
                q.push(i);
            }
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

    bfs(1, adj);
    int maxA = INT_MIN;
    int nodeA;
    for(int i = 1; i <= n; i++) {
        if(level[i] > maxA) {
            maxA = level[i];
            nodeA = i;
        }
    }
    
    vis.assign(N, false);
    level.assign(N, 0);
    bfs(nodeA, adj);
    //cout<<endl;
    int maxB = INT_MIN;
    int nodeB;
    for(int i = 1; i <= n; i++) {
        if(level[i] > maxB) {
            maxB = level[i];
            nodeB = i;
        }
    }
    cout << maxB; // 4 
    // Because if we take nodeA = 5, then 5 8 7 6 9 and 5 4 2 1 
   
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

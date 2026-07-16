#include <bits/stdc++.h>
using namespace std;
/* 
   Suppose we choose city 1.
   If 1 cannot reach some city x, Answer is 1 x.
   Reverse all edges.
   Again DFS from 1.
   If some city x is unreachable
   In the original graph, x cannot reach 1, Answer is x 1.
   Otherwise the graph is strongly connected.
   Complexity: O(N + M)
   
*/
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;

    for (int v : adj[node])
        if (!vis[v])
            dfs(v, adj, vis);
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1), rev(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);

    dfs(1, adj, vis);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << 1 << " " << i;
            return 0;  // as soon as we are finding one valid pair return ans
        }
    }

    fill(vis.begin(), vis.end(), 0);

    dfs(1, rev, vis);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << i << " " << 1;
            return 0;
        }
    }

    cout << "YES";
}
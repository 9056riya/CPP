#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
    vis[node] = 1;
    for (int v : adj[node])
        if (!vis[v])
            dfs1(v, adj, vis, st);

    st.push(node);
}

void dfs2(int node, vector<vector<int>>& rev, vector<int>& vis, vector<int>& comp) {
    vis[node] = 1;
    comp.push_back(node);

    for (int v : rev[node])
        if (!vis[v]) dfs2(v, rev, vis, comp);
}

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;

    for (int v : adj[node])
        if (!vis[v]) dfs(v, adj, vis);
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

    stack<int> st;
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(i, adj, vis, st);

    fill(vis.begin(), vis.end(), 0);

    vector<vector<int>> scc;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!vis[node]) {
            vector<int> comp;
            dfs2(node, rev, vis, comp);
            scc.push_back(comp);
        }
    }

    if (scc.size() == 1) {
        cout << "YES";
        return 0;
    }

    int a = scc[0][0];
    int b = scc[1][0];

    fill(vis.begin(), vis.end(), 0);
    dfs(a, adj, vis);

    cout << "NO\n";

    if (vis[b])
        cout << b << " " << a;
    else
        cout << a << " " << b;
}
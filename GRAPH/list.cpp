#include<bits/stdc++.h>
using namespace std;
int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    // edges: 0-1, 0-2, 1-3
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    // print adjacency list
    for(int i = 0; i < V; i++) {
        cout << i << ": ";
        for(int x : adj[i])
            cout << x << " ";
        cout << "\n";
    }
}
#include<bits/stdc++.h>
using namespace std;

void DFS(int node,vector<vector<int>> &adj,vector<int>&dfs,int V,vector<int>&vis){
    vis[node]=1;
    dfs.push_back(node);
    for(int i:adj[node]){
        if(!vis[i]){
            DFS(i,adj,dfs,V,vis);
        }
    }
}

int main(){
int V = 5;
    vector<vector<int>> adj(V);
    // edges: 0-1, 0-2, 1-3
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    vector<int>vis(V,0);
    vector<int>dfs;
    DFS(0,adj,dfs,V,vis);
    //show result
    cout<<"answer:\n";
    for(int i:dfs){
        cout<<i<<" ";
    }
    return 0;
}
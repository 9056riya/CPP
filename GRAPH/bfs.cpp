#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>&adj,vector<int>&bfs,int V){
    int vis[V]={0};
    vis[0]=1; //0 is source node
    queue<int>q;
    q.push(0);
    while(!q.empty()){
      int node=q.front();
      q.pop();
      bfs.push_back(node);

      for(int i:adj[node]){
        if(!vis[i]){
            vis[i]=1;
            q.push(i);
        }
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

    
    vector<int>bfs;
    BFS(adj,bfs,V);
    //show result
    cout<<"answer:\n";
    for(int i=0;i<bfs.size();i++){
        cout<<bfs[i]<<" ";
    }

    return 0;
}
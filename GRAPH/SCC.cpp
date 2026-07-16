#include<bits/stdc++.h>
using namespace std;
/* kosaraju or Tarjan algorithm (specially for directed graph)
  1.sort all accortding to finish timing or u->v (topo sort)
  2.Transpose the Graph (reversing all edge of graph)
  3.Dfs according to element in stack of topo sort

*/

void toposort(int node,vector<vector<int>>&adj,stack<int>&st,vector<int>&vis){
    vis[node]=1;

    for(auto it:adj[node]){
       if(!vis[it]) toposort(it,adj,st,vis);
    }
    st.push(node);
}
void revdfs(int node,vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=1;
    cout<<node<<" ";
    for(auto it:adj[node]){
       if(!vis[it]) revdfs(it,adj,vis);
    }
}
int main(){
   int n,m; //n=no of node,m=no of edges
   //cout<<"Enter n amd m:"<<endl;
   cin>>n>>m;
   vector<vector<int>>adj(n);
   //cout<<"Enter u->v:"<<endl;
    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
    }
    vector<int>vis(n,0);
    
    stack<int>st;
    //topo sort
    for(int i=0;i<n;i++){
        if(!vis[i])  toposort(i,adj,st,vis);
    }
    

    //transpose of graph O(n+e);
    vector<vector<int>>transposedadj(n);
    fill(vis.begin(), vis.end(), 0);
    for(int i=0;i<n;i++){
         //reset vis vis[i]=0;
        for(auto it:adj[i]){
            transposedadj[it].push_back(i);
        }
    }
    
    //dfs
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            cout<<"SCC:";
            revdfs(node,transposedadj,vis);
            cout<<endl;
        }    
    }

    return 0;
}
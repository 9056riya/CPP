#include<bits/stdc++.h>
using namespace std;
void toposort(int node,vector<vector<int>>&adj,stack<int>&st,vector<int>&vis){
    vis[node]=1;

    for(auto it:adj[node]){
       if(!vis[it]) toposort(it,adj,st,vis);
    }
    st.push(node);
}
void revdfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&temp){
    vis[node]=1;
    temp.push_back(node);
    for(auto it:adj[node]){
       if(!vis[it]) revdfs(it,adj,vis,temp);
    }
}
int main(){
   int n,m; //n=no of node,m=no of edges
   //cout<<"Enter n amd m:"<<endl;
   cin>>n>>m;
   vector<vector<int>>adj(n+1);
   //cout<<"Enter u->v:"<<endl;
    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
    }
    vector<int>vis(n+1,0);
    
    stack<int>st;
    //topo sort
    for(int i=1;i<=n;i++){
        if(!vis[i])  toposort(i,adj,st,vis);
    }
    

    //transpose of graph O(n+e);
    vector<vector<int>>transposedadj(n+1);
    fill(vis.begin(), vis.end(), 0);
    for(int i=1;i<=n;i++){
         //reset vis vis[i]=0;
        for(auto it:adj[i]){
            transposedadj[it].push_back(i);
        }
    }
    
    //dfs
    vector<vector<int>>scc;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
           vector<int>temp;
           
            revdfs(node,transposedadj,vis,temp);
           scc.push_back(temp);
        }    
    }
    cout<<scc.size()<<endl;
    for(int i=1;i<=scc.size();i++){
        for(auto it:scc[i]){
            cout<<i<<" ";
        }
    }
       
        
    return 0;
}
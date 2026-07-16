#include<bits/stdc++.h>
using namespace std;
class DisjoinSet{
vector<int>rank,parent,size;
public:
//constructor
  DisjoinSet(int n){
   rank.resize(n+1,0);
   parent.resize(n+1);
   size.resize(n+1);
   for(int i=0;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
  }
   // find ultimate parent
   int findulpar(int node){
       if(node==parent[node]) return node;
       return parent[node]=findulpar(parent[node]);
   }
    void unionByrank(int u,int v){
        int ulp_u=findulpar(u);
        int ulp_v=findulpar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
              parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }

    }
    
    void unionBysize(int u,int v){
    int ulp_u=findulpar(u);
    int ulp_v=findulpar(v);
    if(ulp_u==ulp_v) return;

    if(size[ulp_u] < size[ulp_v]){
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else{
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
}

};

int main(){
    DisjoinSet ds(7);
    ds.unionBysize(1,2);
    ds.unionBysize(2,3);
    ds.unionBysize(4,5);
    ds.unionBysize(6,7);
    ds.unionBysize(5,6);
    //  do 3 and 7 belongs to same set
 if(ds.findulpar(3)==ds.findulpar(7)){
    cout<<"same\n";
 }
 else{
    cout<<"not same\n";
 }
    ds.unionBysize(3,7);

if(ds.findulpar(3)==ds.findulpar(7)){
    cout<<"same\n";
 }
 else{
    cout<<"not same\n";
 }
    return 0;
}
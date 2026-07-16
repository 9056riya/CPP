#include <bits/stdc++.h> 
using namespace std;
int helper(int ind,vector<int>& arr){
        int n=arr.size();
        if(ind==0) return arr[0];
        int maxSum=INT_MIN;
        for(int i=1;i<n;i++){
            if(ind>=i)
        
        maxSum=max(maxSum,helper(ind-i-1,arr)+arr[ind-i]);   
            cout<<i<<"  "<<maxSum<<endl;
        }
        return maxSum;
    }
    int main() {
        // code here
vector<int>arr={5, 5, 10, 100, 10, 5};
        int n=arr.size()-1;
        cout<<helper(n,arr);
        return 0;
    }
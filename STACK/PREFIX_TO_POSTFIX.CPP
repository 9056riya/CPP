#include<bits/stdc++.h>
using namespace std;
int leftmost(vector<int>& arr, int target){
         int ans=0;
         int l=0,r=arr.size()-1;
         while(l<=r){
             int mid=l+(r-l)/2;
             if(arr[mid]==target){
                 ans=mid;
                 cout<<"ans1:"<<ans<<endl;
                 r=mid-1;
             }
             else if(arr[mid]<target) l=mid+1;
             else r=mid-1;
         }
         cout<<"ans1:"<<ans<<endl;
         return ans;
     }
     int rightmost(vector<int>& arr, int target){
         int ans=0;
         int l=0,r=arr.size()-1;
         while(l<r){
             int mid=l+(r-l)/2;
             if(arr[mid]==target){
                 ans=mid;
                 l=mid+1;
             }
             else if(arr[mid]>target) r=mid-1;
             else l=mid+1;
         }
         cout<<"ans2:"<<ans<<endl;
         return ans;
     }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int startInd=leftmost(arr,target);
        int lastInd=rightmost(arr,target);
        cout<<lastInd-startInd+1<<endl;
    }
    int main(){
         vector<int>arr={1,1 ,2 ,2 ,2, 2 ,3};
         int target=2;
         countFreq(arr,target);
        return 0;
    }
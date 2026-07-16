#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool flag=true;
        int cnt1=0,cnt2=0;
        if(n%2)  flag=false;
        else{
        
            for(int i=0;i<n;i++){
                if(s[i]=='('){
                    cnt1++;
                }
                else cnt2++;
            }
        }
        if(cnt1!=cnt2) flag=false;
        if(!flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
    }
    
    return 0;
}
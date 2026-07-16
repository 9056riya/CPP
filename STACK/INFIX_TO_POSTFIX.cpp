#include<bits/stdc++.h>
using namespace std;
int precedence(char ch){
if(ch=='^') return 3;
else if(ch=='*'||ch=='/') return 2;
else if(ch=='+'||ch=='-') return 1;
else return -1;
}
void infixTopostfix(string s){
    string ans="";
     stack<char>st;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(isalnum(ch)) ans+=ch;
        else if(ch=='('){
            st.push(ch);
        }
        else if (ch == ')') {
            while (st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();  // Pop the ‘(‘ from the stack
        }
        else{
            while(!st.empty()&&precedence(st.top())>=precedence(ch)){
                ans+=st.top();
                st.pop();
            }
            st.push(ch);
        }

    }
    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    cout << "Postfix expression: " << ans << endl;  // Output the result
}
int main(){
   string exp = "(p+q)*(m-n)";  // Infix expression
    cout << "Infix expression: " << exp << endl;
    infixTopostfix(exp);  // Convert the infix expression to postfix
    return 0;
}

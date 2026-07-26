#include<bits/stdc++.h>
using namespace std;
class ListNode{
public:
    int data;
    ListNode *next;
    ListNode(int data){
        this->data=data;
        next=nullptr;
    }
};
int length(ListNode *head){
    int cnt=0;
    ListNode *temp=head;
    while(temp!=NULL){
       temp=temp->next;
       cnt++;
    }
    return cnt;
}
bool search(ListNode *head,int target){
    ListNode *temp=head;
    while(temp->data!=target){
       temp=temp->next;
    }
    return (temp!=NULL);
}

int main(){
    ListNode * head=new ListNode(0);
    head->next=new ListNode(1);
    head->next->next=new ListNode(2);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(4);
    
    cout<<"LEN:"<<length(head)<<endl;
    cout<< boolalpha<<search(head,2)<<endl;
}
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
ListNode *convertArrtoLL(int arr[],int n){
    ListNode *head=new ListNode(arr[0]);
    ListNode *prev=head;
    
    for(int i=1;i<n;i++){
       ListNode *curr=new ListNode(arr[i]);
       prev->next=curr;
       prev=curr;
    }
    return head;
}
void printList(ListNode* head) {
        ListNode* temp = head;
        while (temp != nullptr) {
           cout << temp->data << "->";
           temp = temp->next;
        }
      cout << endl;
    }
int main(){
    int arr[5]={5,4,6,7,8};
    ListNode *head=convertArrtoLL(arr,5);
    cout<<"LIST:"<<endl;
    printList(head);
}
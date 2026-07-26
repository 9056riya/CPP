#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
  int data;
  ListNode* next;

  ListNode(int x){
    data=x;
    next=nullptr;
  }
  ListNode(int x,ListNode* ptr){
    data=x;
    next=ptr;
  }
};
class Solution{
public: 

  ListNode* insertAtHead(ListNode* head,int data){
    ListNode* newNode=new ListNode(data,head);
        
    head=newNode;
    return head;
  }

  ListNode* insertAtpos(ListNode* head,int data,int pos){
    ListNode* newNode=new ListNode(data);
    ListNode* temp=head;
    int cnt=0;
    while(cnt+1!=pos){
      temp=temp->next;
      cnt++;
    }
    newNode->next=temp->next;  
    temp->next=newNode;
    return head;
  }

  ListNode* insertAtend(ListNode* head,int data){
    ListNode* newNode=new ListNode(data);
    if(head == nullptr) return newNode;
    ListNode* temp=head;
    while(temp->next!=NULL){
      temp=temp->next;
    }
  temp->next=newNode;
  return head;
  }

  void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};
int main(){
  Solution sol;
  ListNode* head=new ListNode(1);
  head->next=new ListNode(2);
   
  cout << "Original List: ";
  sol.printList(head);

  
  head = sol.insertAtHead(head, 0); // Inserting new node at head

  sol.insertAtpos(head,4,3);  //inserting at pos

 
  sol.insertAtend(head,5);  //inserting at end
  cout << "After Insertion : ";
  sol.printList(head);
  return 0;
}
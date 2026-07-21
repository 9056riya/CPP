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
    ListNode* insertAtHead(ListNode* head,int x){
        ListNode* newNode=new ListNode(x,head);
        
        head=newNode;
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
   ListNode* head=new ListNode(5);
   head->next=new ListNode(8);
   
    cout << "Original List: ";
    sol.printList(head);

    // Inserting new node at head
    head = sol.insertAtHead(head, 1);

    cout << "After Insertion at Head: ";
    sol.printList(head);

    return 0;
}
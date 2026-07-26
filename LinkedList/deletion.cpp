#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int data;
    ListNode *next;
    ListNode(int x){
      data=x;
      next=nullptr;
    }
};
class Solution{
public:
    ListNode *deleteAtstart(ListNode * head){
        head=head->next;
        return head;
    }
    ListNode *deleteAtend(ListNode * head){
        ListNode *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        return head;
    }
    ListNode *deleteAtpos(ListNode * head,int pos){
       ListNode* temp=head;
        int cnt=0;
        while(cnt+1!=pos){
           temp=temp->next;
           cnt++;
        }
       
       temp->next=temp->next->next;
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
    ListNode * head=new ListNode(0);
    head->next=new ListNode(1);
    head->next->next=new ListNode(2);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(4);
    cout << "Original List: ";
    sol.printList(head);
    head=sol.deleteAtstart(head);
    sol.deleteAtend(head);
    sol.deleteAtpos(head,2);
    cout << "Modified List: ";
    sol.printList(head);
    
}
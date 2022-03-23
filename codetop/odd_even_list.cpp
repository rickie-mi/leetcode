#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v=0, ListNode* ne=nullptr):val(v),next(ne){}
};


ListNode* merge(ListNode *head1, ListNode* head2){
    ListNode *dummy = new ListNode(0,nullptr);
    ListNode *cur1=head1, *cur2=head2, *cur=dummy;
    while(cur1 && cur2){
        if(cur1->val<cur2->val)
        {
            cur->next=cur1;
            cur1=cur1->next;
            cur=cur->next;
        }
        else
        {
            cur->next=cur2;
            cur2=cur2->next;
            cur=cur->next;
        }
    }
    if(cur1) cur->next=cur1;
    if(cur2) cur->next=cur2;
    return dummy->next;
}

ListNode* solution(ListNode *head){
    if(head==nullptr || head->next==nullptr) return head;
    ListNode *head2 = head->next;
    ListNode *cur1=head, *cur2=head2;
    while(cur2 && cur2->next){
        cur1->next=cur2->next;
        cur1 = cur1->next;
        cur2->next=cur1->next;
        cur2 =cur2->next;
    }
    cur1->next=nullptr; cur2->next=nullptr;
    ListNode *pre=nullptr; cur2=head2;
    while(cur2)
    {
        ListNode *temp = cur2->next;
        cur2->next=pre;
        pre=cur2;
        cur2=temp;
    }
    head2 = pre;
    return merge(head,head2);
}

int main(){
    int a[8]={1,8,3,6,5,4,7,2};
    ListNode *head = new ListNode(a[0],nullptr);
    ListNode *cur = head;
    for(int i=1; i<8; i++)
    {
        cur->next = new ListNode(a[i],nullptr);
        cur = cur->next;
    }
    head = solution(head);
    cur = head;
    while(cur)
    {
        cout<<cur->val<<endl;
        cur = cur->next;
    }
    return 0;
}
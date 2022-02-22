class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* dummyhead = new ListNode(0,head);
        ListNode *pre = head, *cur=head->next; //pre及之前都排序好了，cur表示下一个需要排序的
        while(cur){
            if(cur->val>=pre->val){
                cur = cur->next;
                pre = pre->next;
                continue;
            }
            //需要插入
            pre->next = cur->next;
            ListNode* temp = dummyhead;
            while(temp->next!=nullptr && temp->next->val<=cur->val){
                temp = temp->next;
            }
            cur->next = temp->next;
            temp->next = cur;
            cur = pre->next;
        }
        return dummyhead->next;
    }
};
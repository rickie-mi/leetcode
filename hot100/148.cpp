class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *dummy = new ListNode(0,head);
        int totlen = 0; ListNode* temp = head;
        while(temp){
            temp = temp->next;
            totlen++;
        }
        for(int sublen=1; sublen<totlen; sublen*=2){
            ListNode *pre=dummy, *cur=dummy->next;
            while(cur){
                ListNode *head1 = cur;
                for(int i=1; i<sublen && cur->next!=nullptr; i++)
                    cur = cur->next;
                ListNode *head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                for(int i=1; i<sublen && cur!=nullptr && cur->next!=nullptr; i++)
                    cur = cur->next;
                ListNode *nextone = nullptr;
                if(cur){
                    nextone = cur->next;
                    cur->next = nullptr;
                }
                ListNode *mergeone = merge(head1, head2);
                pre->next = mergeone;
                while(pre->next)
                    pre = pre->next;
                cur = nextone;
            } 
        }
        return dummy->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }

};
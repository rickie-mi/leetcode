class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *cur=head, *pre=dummy, *ne;
        int len = 0;
        while(head)
        {
            head = head->next;
            len++;
        }
        for(int i=0; i<len/k; i++)
        {
            for(int j=0; j<k-1; j++)
            {
                ne = cur->next;
                cur->next = ne->next;
                ne->next = pre->next;
                pre->next = ne;
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};
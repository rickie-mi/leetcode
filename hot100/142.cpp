class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while(fast!=nullptr && slow!=nullptr){
            fast = fast->next;
            slow = slow->next;
            if(fast!=nullptr){
                fast = fast->next;
                if(fast == slow) break;
            } 
        }
        if(fast == nullptr) return nullptr;
        slow = head;
        while(slow != fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
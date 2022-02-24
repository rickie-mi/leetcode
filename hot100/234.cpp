class Solution {
private:
    ListNode* head2;
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode* fast = head, *slow = head;
        while(fast!=nullptr){
            fast = fast->next;
            slow = slow->next;
            if(fast) fast = fast->next;
        }

        reverseList(slow);
        //cout<<head2->val;
        //return true;
        return isPalindrome(head2, head);
    }

    bool isPalindrome(ListNode* head1, ListNode* head2){
        while(head1 && head2){
            if(head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head){
        if(head->next == nullptr){
            head2 = head;
            return head;
        }
        ListNode* temp = reverseList(head->next);
        temp->next = head;
        head->next = nullptr;
        return head;
    }

};
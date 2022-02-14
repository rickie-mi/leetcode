/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode((l1->val+l2->val)%10);
        int pre = (l1->val+l2->val)/10;
        l1=l1->next; l2=l2->next;
        ListNode *cur = head;
        while(l2 && l1){
            ListNode *temp = new ListNode((l1->val+l2->val+pre)%10);
            pre = (l1->val+l2->val+pre)/10;
            cur->next = temp;
            l1 = l1->next; l2=l2->next; cur = temp;
        }
        while(l1){
            ListNode *temp = new ListNode((l1->val+pre)%10);
            pre = (l1->val+pre)/10;
            cur->next = temp;
            l1 = l1->next; cur = temp;
        }
        while(l2){
            ListNode *temp = new ListNode((l2->val+pre)%10);
            pre = (l2->val+pre)/10;
            cur->next = temp;
            l2 = l2->next; cur = temp;
        }
        if(pre){
            cur->next = new ListNode(pre);
        }
        return head;
    }
};
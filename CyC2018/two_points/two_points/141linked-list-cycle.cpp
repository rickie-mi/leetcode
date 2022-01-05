struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (head == nullptr) return false;
    ListNode* slow = head, * fast = head->next;
    while (fast != nullptr)
    {
        if (fast->next == slow)
            return true;
        slow = slow->next;
        fast = fast->next;
        if (fast) fast = fast->next;
    }
    return false;
}
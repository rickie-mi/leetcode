#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	
};

ListNode* reverseList1(ListNode* head) {
	//递归法
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *last = reverseList1(head->next);
	head->next->next = head;
	head->next = NULL;
	return last;
}

ListNode* reverseList2(ListNode* head) {
	//迭代法
	if (head == NULL) return NULL;
	ListNode* cur1 = head, *cur2 = head->next;
	while (cur2 != NULL)
	{
		//cout<<cur1->val<<' '<<cur2->val<<endl;
		ListNode *temp = cur2->next;
		cur2->next = cur1;
		cur1 = cur2;
		cur2 = temp;
	}
	head->next = NULL;  //必须要加这个
	return cur1;
}
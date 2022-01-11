#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

};

ListNode* reverseBetween2(ListNode* head, int left, int right) {
	//迭代法
	if (left == right) return head;  //不需要调换
	ListNode* dummy = new ListNode();
	dummy->next = head;
	int cnt = 1;
	ListNode* pre = dummy;
	ListNode *cur = head;
	while (cnt<left)
	{
		pre = cur;
		cur = cur->next;
		cnt++;
	}
	ListNode *leftnode = cur;
	ListNode *cur1 = cur, *cur2 = cur->next;
	while (cnt<right && cur2 != NULL)
	{
		ListNode* temp = cur2->next;
		cur2->next = cur1;
		cur1 = cur2;
		cur2 = temp;
		cnt++;
	}
	leftnode->next = cur2;
	pre->next = cur1;
	return dummy->next;
}



//递归法
ListNode *successor;
ListNode* reverseN(ListNode* head, int n)
{
	if (n == 1)
	{
		successor = head->next;
		return head;
	}
	ListNode *last = reverseN(head->next, n - 1);
	head->next->next = head;
	head->next = successor;
	return last;
}
ListNode* reverseBetween1(ListNode* head, int left, int right) {
	//递归法
	if (left == 1)
	{
		return reverseN(head, right);
	}
	head->next = reverseBetween1(head->next, left - 1, right - 1);
	return head;
}
#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	
};

class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		int ll = 0, rr = nums.size() - 1;
		TreeNode *head = constructTree(nums, ll, rr);
		return head;
	}
	TreeNode* constructTree(vector<int>& nums, int ll, int rr)
	{
		if (ll > rr) return nullptr;
		int idx = -1;
		int maxvalue = INT_MIN;
		for (int i = ll; i <= rr; i++)
		{
			if (nums[i] > maxvalue)
			{
				maxvalue = nums[i];
				idx = i;
			}
		}
		TreeNode *root = new TreeNode(maxvalue);
		root->left = constructTree(nums, ll, idx - 1);
		root->right = constructTree(nums, idx + 1, rr);
		return root;
	}
};
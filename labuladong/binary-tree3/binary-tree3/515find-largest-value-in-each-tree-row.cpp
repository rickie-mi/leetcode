#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
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
	vector<int> largestValues(TreeNode* root) {
		vector<int> ans;
		if (root == nullptr) return ans;
		queue<TreeNode*> q;
		q.push(root);
		while (q.size())
		{
			int sz = q.size();
			int maxans = INT_MIN;
			for (int i = 0; i<sz; i++)
			{
				auto temp = q.front();
				q.pop();
				maxans = max(maxans, temp->val);
				if (temp->left) q.push(temp->left);
				if (temp->right) q.push(temp->right);
			}
			ans.push_back(maxans);
		}
		return ans;
	}
};
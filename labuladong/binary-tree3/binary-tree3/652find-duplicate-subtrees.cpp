#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
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
private:
	unordered_map<string, int> mp;
	vector<TreeNode*> res;
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		reverse(root);
		return res;
	}

	string reverse(TreeNode *root)
	{
		if (root == nullptr) return "#";
		string ll = reverse(root->left);
		string rr = reverse(root->right);
		//序列化的话前序和后序都可以唯一确定二叉树
		//但中序不可以
		string ans = to_string(root->val) + "," + ll + "," + rr;
		if (mp.count(ans) == 0)
		{
			mp[ans] = 1;
		}
		else
		{
			if (mp[ans] == 1)
				res.push_back(root);
			mp[ans] ++;
		}
		return ans;
	}

};
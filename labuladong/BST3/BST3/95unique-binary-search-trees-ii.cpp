#include <iostream>
#include <vector>
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
	vector<TreeNode*> generateTrees(int n) {
		return find(1, n);
	}

	vector<TreeNode*> find(int lo, int hi)
	{
		vector<TreeNode*> res;
		if (lo>hi)
		{
			res.push_back(nullptr);
			return res;
		}
		for (int i = lo; i <= hi; i++)
		{
			auto lls = find(lo, i - 1);
			auto rrs = find(i + 1, hi);
			for (auto ll : lls)
			{
				for (auto rr : rrs)
				{
					TreeNode *root = new TreeNode(i);
					root->left = ll;
					root->right = rr;
					res.push_back(root);
				}
			}
		}
		return res;
	}
};
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}

	TreeNode* build(vector<int>& inorder, int inleft, int inright, vector<int>& postorder, int postleft, int postright)
	{
		if (inleft > inright || postleft > postright) return nullptr;
		int v = postorder[postright];
		int idx = -1;
		for (int i = inleft; i <= inright; i++)
		{
			if (inorder[i] == v)
			{
				idx = i;
				break;
			}
		}
		int ll = idx - inleft;
		TreeNode *root = new TreeNode(v);
		root->left = build(inorder, inleft, idx - 1, postorder, postleft, postleft + ll - 1);
		root->right = build(inorder, idx + 1, inright, postorder, postleft + ll, postright - 1);
		return root;
	}
};
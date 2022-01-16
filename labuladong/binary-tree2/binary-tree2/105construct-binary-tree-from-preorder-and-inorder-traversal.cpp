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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
	TreeNode* build(vector<int>& preorder, int preleft, int preright, vector<int>& inorder, int inleft, int inright)
	{
		if (preleft > preright || inleft > inright)
			return nullptr;
		TreeNode* root = new TreeNode(preorder[preleft]);
		int idx = -1;
		for (int i = inleft; i <= inright; i++)
		{
			if (inorder[i] == preorder[preleft])
			{
				idx = i;
				break;
			}
		}
		int ll = idx - inleft, rr = inright - idx;
		root->left = build(preorder, preleft + 1, preleft + ll, inorder, inleft, idx - 1);
		root->right = build(preorder, preleft + ll + 1, preright, inorder, idx + 1, inright);
		return root;
	}
};
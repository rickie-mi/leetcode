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
	TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
		return construct(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
	}

	TreeNode* construct(vector<int>& preorder, int preleft, int preright, vector<int>& postorder, int postleft, int postright)
	{
		if (preleft > preright || postleft > postright)
			return nullptr;
		if (preleft == preright)
			return new TreeNode(preorder[preleft]);
		int v = preorder[preleft];
		int vv = preorder[preleft + 1];
		int idx = -1;
		for (int i = postleft; i <= postright; i++)
		{
			if (postorder[i] == vv)
			{
				idx = i;
				break;
			}
		}
		int ll = idx - postleft + 1;
		TreeNode* root = new TreeNode(v);
		root->left = construct(preorder, preleft + 1, preleft + ll, postorder, postleft, idx);
		root->right = construct(preorder, preleft + ll + 1, preright, postorder, idx + 1, postright - 1);
		return root;
	}
};
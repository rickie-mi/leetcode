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
	bool isValidBST(TreeNode* root) {
		return checkBST(root, nullptr, nullptr);
	}
	bool checkBST(TreeNode* root, TreeNode* upper, TreeNode* downner)
	{
		if (root == nullptr)
			return true;
		if (upper && upper->val <= root->val)
			return false;
		if (downner && downner->val >= root->val)
			return false;
		return checkBST(root->left, root, downner) && checkBST(root->right, upper, root);
	}
};
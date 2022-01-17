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
	int ans;
public:
	TreeNode* convertBST(TreeNode* root) {
		ans = 0;
		sumBST(root);
		return root;
	}
	void sumBST(TreeNode* root)
	{
		if (root == nullptr)
			return;
		sumBST(root->right);
		ans += root->val;
		root->val = ans;
		sumBST(root->left);
	}
};
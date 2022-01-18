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
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) return nullptr;
		if (root->val == key)
		{
			if (root->left == nullptr) return root->right;
			else if (root->right == nullptr) return root->left;
			TreeNode *maxNode = getMax(root->left, key);
			root->left = deleteNode(root->left, maxNode->val);
			maxNode->left = root->left;
			maxNode->right = root->right;
			root = maxNode;
		}
		else if (root->val > key)
			root->left = deleteNode(root->left, key);
		else
			root->right = deleteNode(root->right, key);
		return root;
	}
	TreeNode* getMax(TreeNode *root)
	{
		while (root->right != nullptr)
		{
			root = root->right;
		}
		return root;
	}
};
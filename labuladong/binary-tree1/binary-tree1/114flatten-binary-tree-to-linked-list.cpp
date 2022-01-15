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
	void flatten(TreeNode* root) {
		if (root == nullptr) return;
		flatten(root->left);
		flatten(root->right);
		//这里假设左右节点都已经拉平了
		TreeNode *ll = root->left;
		TreeNode *rr = root->right;
		root->left = nullptr;
		root->right = ll;
		while (root->right != nullptr)
		{
			root = root->right;
		}
		root->right = rr;

	}
};

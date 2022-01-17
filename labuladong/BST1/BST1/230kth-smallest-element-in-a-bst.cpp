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
	int cnt;
	int ans;
public:
	int kthSmallest(TreeNode* root, int k) {
		cnt = 0;
		search(root, k);
		return ans;
	}

	void search(TreeNode* root, int& k)
	{
		if (root == nullptr)
			return;
		if (cnt > k)
			return;
		search(root->left, k);
		cnt++;
		if (cnt == k) ans = root->val;
		search(root->right, k);
	}
};
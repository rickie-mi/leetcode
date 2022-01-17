#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
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
	int maxlen;
public:
	int diameterOfBinaryTree(TreeNode* root) {
		maxlen = 0;
		search(root);
		return maxlen;
	}
	int search(TreeNode *root)
	{
		if (root == nullptr) return 0;
		int ll = search(root->left);
		int rr = search(root->right);
		maxlen = max(ll + rr, maxlen);
		//cout<<ll+rr<<root->val<<endl;
		return max(ll, rr) + 1;
	}
};
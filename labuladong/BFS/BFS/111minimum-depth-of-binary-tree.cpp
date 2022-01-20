#include<queue>
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
	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int cnt = 0;
		queue<TreeNode*> q;
		q.push(root);
		while (q.size())
		{
			cnt++;
			int sz = q.size();
			while (sz--)
			{
				TreeNode *temp = q.front();
				q.pop();
				if (temp->left == nullptr && temp->right == nullptr)
					return cnt;
				if (temp->left) q.push(temp->left);
				if (temp->right) q.push(temp->right);
			}
		}
		return -1;
	}
};
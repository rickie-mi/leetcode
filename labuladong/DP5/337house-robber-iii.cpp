/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//法一
class Solution {
private:
    unordered_map<TreeNode*, int> mp;
public:
    int rob(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if(mp.count(root))
            return mp[root];
        int res;
        if(root->left == nullptr && root->right == nullptr)
        {
            res = root->val;
            mp[root] = res;
            return res;
        }
        if(root->left == nullptr)
        {
            res = max(root->val + rob(root->right->left) + rob(root->right->right), rob(root->right));
            mp[root] = res;
            return res;
        }
        if(root->right == nullptr)
        {
            res = max(root->val + rob(root->left->left) + rob(root->left->right), rob(root->left));
            mp[root] = res;
            return res;
        }
        res = max(root->val + rob(root->left->left) + rob(root->left->right) + rob(root->right->left) + rob(root->right->right), rob(root->right)+rob(root->left));
        mp[root]= res;
        return res;
    }
};

//法二
class Solution {
public:
    int rob(TreeNode* root) {
        auto res = dp(root);
        return max(res[0],res[1]);
    }

    //第一个参数是不加该点
    //第二个参数是加上该点
    vector<int> dp(TreeNode *root)
    {
        if(root == nullptr) return vector<int>{0,0};
        auto res1 = dp(root->left);
        auto res2 = dp(root->right);
        return vector<int>{max(res1[0],res1[1])+max(res2[0],res2[1]), root->val+res1[0]+res2[0]};
    }
};
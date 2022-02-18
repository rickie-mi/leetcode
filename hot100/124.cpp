class Solution {
private:
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        check(root);
        return res;
    }

    int check(TreeNode* root)
    {
        if(root==nullptr) return 0;
        int ll = max(check(root->left),0);
        int rr = max(check(root->right),0);
        res = max(ll+rr+root->val, res);
        return max(ll,rr)+root->val;
    }
};
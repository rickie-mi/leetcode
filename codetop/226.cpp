class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;
        stack<TreeNode*> stk;
        stk.push(root);
        while(stk.size())
        {
            TreeNode *tt = stk.top(); stk.pop();
            TreeNode *temp = tt->left;
            tt->left = tt->right;
            tt ->right = temp;
            if(tt->left) stk.push(tt->left);
            if(tt->right) stk.push(tt->right);
        }
        return root;
    }
};
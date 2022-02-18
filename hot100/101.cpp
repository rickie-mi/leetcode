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

//迭代方式
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(q.size())
        {
            auto c1 = q.front();
            q.pop();
            auto c2 = q.front();
            q.pop();
            if(c1 == nullptr && c2 ==nullptr) continue;
            if(c1 == nullptr || c2 == nullptr) return false;
            if(c1->val != c2->val) return false;
            q.push(c1->left); q.push(c2->right);
            q.push(c1->right); q.push(c2->left);
        }
        return true;
    }
};

//递归方式
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return check(root->left, root->right);
    }

    bool check(TreeNode* node1, TreeNode* node2){
        if(node1 == nullptr && node2 == nullptr)
            return true;
        if(node1 == nullptr || node2 == nullptr)
            return false;
        if(node1->val != node2->val) return false;
        return check(node1->left, node2->right) && check(node1->right, node2->left);
    }

};
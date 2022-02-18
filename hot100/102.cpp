class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto c = q.front();
                q.pop();
                temp.push_back(c->val);
                if(c->left) q.push(c->left);
                if(c->right) q.push(c->right);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};
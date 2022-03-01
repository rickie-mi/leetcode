class Solution {
public:
    unordered_map<long long, int> premix;
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return 0;
        premix[0] = 1; //前缀和初始化
        return dfs(root, 0, targetSum);
    }

    int dfs(TreeNode* root, int cur, int targetSum){
        if(root==nullptr) return 0;
        cur += root->val;
        int res = 0;
        if(premix.count(cur-targetSum))
            res += premix[cur-targetSum];
        premix[cur]++;
        res += dfs(root->left, cur, targetSum);
        res += dfs(root->right, cur, targetSum);
        premix[cur]--;
        return res;
    }
};
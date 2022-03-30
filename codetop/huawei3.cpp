class Solution {
private:
    unordered_map<string, int> mp;
    TreeNode* res;
    int maxdepth;

public:
    TreeNode* findDuplicateSubtrees(TreeNode* root) {
        maxdepth = 0;
        save(root);
        return res;
    }


    pair<string,int> save(TreeNode* root) {
        if (root == nullptr) return { "#",0 };
        auto ll = save(root->left);
        auto rr = save(root->right);
        string llstr = ll.first, rrstr = rr.first;
        int lldep = ll.second, rrdep = rr.second;
        string ans = to_string(root->val) + "," + llstr + "," + rrstr;
        int dep = max(lldep, rrdep) + 1;
        if (mp.find(ans) == mp.end())
        {
            mp[ans] = 1;
            return { ans,dep };
        }
        else
        {
            mp[ans]++;
            if (dep > maxdepth) {
                res = root; maxdepth = dep;
            }
            return { ans,dep };
        }
    }
};
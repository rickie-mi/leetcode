class Solution {
private:
    vector<TreeNode*> plist, qlist;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> list{root};
        search(root,p,list);
        plist = qlist;
        //for(auto c: plist) cout<<c->val<<' ';
        //cout<<endl;
        list.clear(); list.push_back(root);
        search(root,q,list);
        //for(auto c: qlist) cout<<c->val<<' ';
        //cout<<endl;
        TreeNode* ans = nullptr;
        for(int i=0; i<plist.size()&& i<qlist.size(); i++){
            if(plist[i]!=qlist[i])
                break;
            ans = plist[i];
        }
        return ans;
    }
    void search(TreeNode*root, TreeNode* t, vector<TreeNode*>& list){
        if(root == t){
            qlist = list;
            return;
        }
        if(root->left){
            list.push_back(root->left);
            search(root->left,t,list);
            list.pop_back();
        } 
        if(root->right){
            list.push_back(root->right);
            search(root->right,t,list);
            list.pop_back();
        }
    }
};
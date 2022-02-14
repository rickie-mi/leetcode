/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string res="";
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp == nullptr) res+="#,";
            else{
                res+=to_string(temp->val)+",";
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> treelist;
        string temp = "";
        for(auto c: data){
            if(c==',') {treelist.push_back(temp); temp.clear();}
            else temp.push_back(c);
        }
        //for(auto c: treelist) cout<<c<<endl;
        int cnt=0;
        if(treelist.size()==1) return nullptr;
        TreeNode *root = new TreeNode(atoi(treelist[0].c_str()));
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            auto tt = q.front();
            q.pop();
            if(treelist[++cnt] != "#"){
                tt->left = new TreeNode(atoi(treelist[cnt].c_str()));
                q.push(tt->left);
            }
            else
                tt->left = nullptr;
            
            if(treelist[++cnt] != "#"){
                tt->right = new TreeNode(atoi(treelist[cnt].c_str()));
                q.push(tt->right);
            }
            else
                tt->right = nullptr;
            
        }
        return root;
    }
};
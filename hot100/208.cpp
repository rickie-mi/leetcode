class Trie {
private:
    vector<Trie*> children;
    bool isend;
public:
    Trie() {
        children.resize(26, nullptr);
        isend = false;
    }
    
    void insert(string word) {
        Trie *p = this;
        for(int i=0; i<word.size(); i++){
            int t = word[i]-'a';
            if(p->children[t] == nullptr){
                p->children[t] = new Trie();
            }
            p = p->children[t];
        }
        p->isend = true;
    }
    
    bool search(string word) {
        Trie *p = this;
        for(int i=0; i<word.size(); i++){
            int t= word[i]-'a';
            if(p->children[t] == nullptr) return false;
            p = p->children[t];
        }
        return p->isend;
    }
    
    bool startsWith(string prefix) {
        Trie *p = this;
        for(int i=0; i<prefix.size(); i++){
            int t= prefix[i]-'a';
            if(p->children[t] == nullptr) return false;
            p = p->children[t];
        }
        return true;
    }
};
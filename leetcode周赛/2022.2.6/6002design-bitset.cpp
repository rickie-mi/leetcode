class Bitset {
private:
    string temp1;
    string temp2;
    string ans;
    int cnt;
public:
    Bitset(int size) {
        temp1 = string(size,'0');
        temp2 = string(size,'1');
        ans = temp1;
        cnt = 0;
        
    }
    
    void fix(int idx) {
        if(ans[idx]=='0') cnt++;
        if(ans == temp1){
            ans[idx] = temp1[idx] = '1';
            temp2[idx] = '0';
        }
        else{
            ans[idx] = temp2[idx] = '1';
            temp1[idx] = '0';
        }
        
    }
    
    void unfix(int idx) {
        if(ans[idx]=='1') cnt--;
        if(ans == temp1){
            ans[idx] = temp1[idx] = '0';
            temp2[idx] = '1';
        }
        else{
            ans[idx] = temp2[idx] = '0';
            temp1[idx] = '1';
        }
    }
    
    void flip() {
        ans = temp1 == ans ? temp2: temp1;
        cnt = ans.size()-cnt;
    }
    
    bool all() {
        return cnt==ans.size();
    }
    
    bool one() {
        return cnt;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        return  ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
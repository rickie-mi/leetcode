class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0) return 0;
        bool pos = num>0; //判断正负
        string temp;
        if(pos==false) 
            temp = to_string(-num);
        else
            temp = to_string(num);
        sort(temp.begin(), temp.end());
        if(pos){
            int i=0;
            while(i<temp.size() && temp[i] == '0')
                    i++;
            swap(temp[i],temp[0]);
            return atoll(temp.c_str());
        }
        else{
            reverse(temp.begin(), temp.end());
            return -atoll(temp.c_str());
        }
    }
};
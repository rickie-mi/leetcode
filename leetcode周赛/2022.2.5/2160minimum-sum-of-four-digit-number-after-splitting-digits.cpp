class Solution {
public:
    int minimumSum(int num) {
        string temp = to_string(num%100) + to_string(num/100);
        sort(temp.begin(), temp.end());
        //return (temp[0]+temp[1]-'0'-'0')*10+(temp[2]+temp[3]-'0'-'0');
        //如果不能有前导零
        if(temp[0] != '0')
            return (temp[0]+temp[1]-'0'-'0')*10+(temp[2]+temp[3]-'0'-'0');
        else if(temp[1]!='0')
            return (temp[1]+temp[2]-'0'-'0')*10+(temp[0]+temp[3]-'0'-'0');
        else
            return (temp[2]+temp[3]-'0'-'0')*10+(temp[0]+temp[1]-'0'-'0');
    }
};
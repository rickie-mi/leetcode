class Solution {
public:
    int gettime(int min, int sec, int start, int pushCost, int moveCost){
        string temp;
        if(min != 0){
            if(sec<10)
                temp = to_string(min)+"0"+to_string(sec);
            else
                temp = to_string(min)+to_string(sec);
        }
            
        else
            temp = to_string(sec);
        //cout<<min<<" "<<sec<<" "<<temp<<endl;
        int push = pushCost*temp.size();
        int cnt = start == temp[0]-'0' ? 0:1;
        //cout<<cnt;
        for(int i=0; i<temp.size()-1; i++)
            if(temp[i] != temp[i+1])
                cnt++;
        //cout<<cnt;
        return cnt*moveCost + push;
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int min = targetSeconds/60, sec = targetSeconds%60;
        if(min==100){
            min=99; sec+=60;
            return gettime(min,sec,startAt,pushCost,moveCost);
        }
        else if(sec > 39){
            return gettime(min,sec,startAt,pushCost,moveCost);
        }
        else{
            int min2 = min-1, sec2 = sec+60;
            int temp1, temp2;
            temp1 = gettime(min,sec,startAt,pushCost,moveCost);
            temp2 = gettime(min2,sec2,startAt,pushCost,moveCost);
            return temp1>temp2 ? temp2:temp1;
        }
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int a[26]={0};
        for(auto c: tasks) a[c-'A']++;
        sort(a,a+26);
        int maxdur = a[25], maxcnt=0;
        for(int i=25; i>=0; i--)
        {
            if(a[i] == maxdur) maxcnt++;
        }
        return max((n+1)*(maxdur-1)+maxcnt, (int)tasks.size());
    }
};
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]>b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> ans(n,vector<int>(2,-1));
        sort(people.begin(), people.end(),cmp);
        for(int i=0; i<n; i++)
        {
            int h = people[i][0], k = people[i][1];
            int cnt=0, idx = 0;
            while(idx<n)
            {
                if(ans[idx][0]==-1)
                {
                    cnt++;
                    if(cnt == k+1)
                    {
                        ans[idx]= people[i];
                        break;
                    }        
                }
                idx++;
            }
            //cout<<people[i][0]<<' '<<people[i][1]<<' '<<idx<<endl;
        }
        return ans;
    }
};
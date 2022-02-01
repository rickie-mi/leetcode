typedef pair<int, int> PII;
class Solution {
private:
    vector<vector<int>> ft;
    vector<vector<int>> wt;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        ft.resize(n);
        wt.resize(n);
        for(auto & flight: flights)
        {
            int a = flight[0], b = flight[1], c = flight[2];
            ft[a].push_back(b);
            wt[a].push_back(c);
        }
        vector<int> dist(n, INT_MAX);
        //vector<int> cur(n,INT_MAX);
        dist[src] = 0;
        //cur[src] = 0;
        int cnt = 0;
        queue<PII> q;
        q.push({src,0});
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                int temp1 = q.front().first, temp2 = q.front().second;
                q.pop();
                for(int j=0; j<ft[temp1].size(); j++)
                {
                    int jj = ft[temp1][j];
                    int path = temp2+wt[temp1][j];
                    if(path < dist[jj])
                    {
                        dist[jj] = path; 
                        q.push({jj,path});
                    }
                   
                }
            }
            //for(int j=0; j<n; j++)
                //dist[j] = cur[j];
            cnt++;
            if(cnt>k) break;            
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
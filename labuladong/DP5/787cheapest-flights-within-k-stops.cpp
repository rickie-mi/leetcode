class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //使用bellman-ford算法
        vector<int> dist(n, INT_MAX);
        vector<int> backup(n,INT_MAX);
        dist[src] = 0; backup[src] = 0;
        //最多经过k+1条边
        for(int i=0; i<=k; i++)
        {
            for(int j=0; j<n; j++)
            {   
                backup[j] = dist[j];
                //cout<<dist[j]<<endl;
            }
                
            for(int j=0; j<flights.size(); j++)
            {
                int a = flights[j][0], b = flights[j][1], c = flights[j][2];
                if(backup[a] != INT_MAX)
                    dist[b] = min(backup[a] + c, dist[b]); 
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
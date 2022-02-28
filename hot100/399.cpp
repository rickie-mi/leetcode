class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=0;
        unordered_map<string,int> mp;
        for(int i=0; i<equations.size(); i++)
        {
            string a = equations[i][0], b = equations[i][1];
            if(mp.count(a)==0) mp[a] = n++;
            if(mp.count(b)==0) mp[b] = n++;
        }
        vector<vector<double>> matrix(n,vector<double>(n,-1));
        for(int i=0; i<values.size(); i++)
        {
            string a = equations[i][0], b = equations[i][1];
            matrix[mp[a]][mp[b]] = values[i];
            matrix[mp[b]][mp[a]] = 1.0/values[i];
        }
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    if(matrix[i][k]>0 && matrix[k][j]>0)
                        matrix[i][j]= matrix[i][k]*matrix[k][j];
        vector<double> ans;
        for(auto query: queries)
        {
            string a = query[0], b = query[1];
            if(mp.count(a)==0 || mp.count(b)==0) 
                ans.push_back(-1);
            else
                ans.push_back(matrix[mp[a]][mp[b]]);
        }
        return ans;
    }
};
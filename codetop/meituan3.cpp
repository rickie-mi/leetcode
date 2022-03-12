#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
int n,m;
void dfs(int cur, int cnt, vector<vector<int>>& people, vector<bool>& dish){
    if(cur==n)
    {
        ans = max(ans,cnt);
        return;
    }
    int a = people[cur][0], b = people[cur][1];
    dfs(cur+1,cnt,people,dish);
    if(dish[a]==true || dish[b]==true) return;
    dish[a] = dish[b] = true;
    dfs(cur+1,cnt+1,people,dish);
    dish[a] = dish[b] = false;
}

int main()
{
    cin>>n>>m;
    vector<bool> dish(m+1,false);
    vector<vector<int>> people(n,vector<int>(2));
    for(int i=0; i<n; i++)
        cin>>people[i][0]>>people[i][1];
    dfs(0,0,people,dish);
    cout<<ans;
    return 0;
}
#include<iostream>
#include <cstring>
#include<vector>
using namespace std;

const int N = 510;
int match[N];
bool st[N];
vector<vector<int>> lines;
int m,n1,n2;

bool find(int u){
    for(auto j: lines[u])
    {
        if(!st[j])
        {
            st[j] = true;
            if(match[j]==0 || find(match[j]))
            {
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin>>n1>>n2>>m;
    lines.resize(n1+1);
    for(int i=0; i<m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        lines[a].push_back(b);
    }
    int res = 0;
    for(int i=1; i<=n1; i++)
    {
        memset(st,false,sizeof st);
        if(find(i)) res++;
    }
    cout<<res;
    return 0;
}
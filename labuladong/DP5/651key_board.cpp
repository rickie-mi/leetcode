#include <iostream>
#include <vector>
using namespace std;

int maxPrint(int n)
{
    vector<int> dp(n+1);
    //base case: 0步操作啥也没
    dp[0] = 0;
    for(int i=1; i<=n; i++)
    {
        dp[i] = dp[i-1]+1;
        for(int j=i-1; j>=2; j--)  //j是ctrl-c的位置
        {
            dp[i] = max(dp[i], dp[j-2]*(i-j+1));
        }
    }
    return dp[n];
}
int main()
{
    int n;
    scanf("%d", &n);
    cout<<maxPrint(n);
    return 0;
}
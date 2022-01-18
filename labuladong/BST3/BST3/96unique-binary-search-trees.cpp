#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

class Solution {
public:
	int numTrees(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		return find(1, n, dp);
	}

	int find(int lo, int hi, vector<vector<int>> & dp)
	{
		if (hi<lo) return 1;
		if (dp[lo][hi] != 0) return dp[lo][hi];
		int ans = 0;
		for (int i = lo; i <= hi; i++)
		{
			ans += find(lo, i - 1, dp) * find(i + 1, hi, dp);
		}
		dp[lo][hi] = ans;
		return ans;
	}
};
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> findAnagrams(string s, string p) {
	vector<int> ans;
	unordered_map<char, int> need, window;
	for (auto c : p)  need[c]++;
	int ll = 0, rr = 0, valid = 0;
	while (rr<s.size())
	{
		char c = s[rr];
		rr++;
		if (need.count(c))
		{
			window[c]++;
			if (window[c] == need[c])
				valid++;
		}
		while (rr - ll >= p.size())
		{
			//cout<<s.substr(ll,rr-ll)<<endl;
			if (valid == need.size())
				ans.push_back(ll);
			char d = s[ll];
			ll++;
			if (need.count(d))
			{
				if (window[d] == need[d])
					valid--;
				window[d]--;
			}
		}
	}
	return ans;
}
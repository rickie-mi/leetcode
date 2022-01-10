#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
	if (s == "") return 0;
	unordered_map<char, int> window;
	int ll = 0, rr = 0;
	int len = -1;
	while (rr<s.size())
	{
		char c = s[rr];
		rr++;
		window[c]++;
		while (window[c] > 1)
		{
			char d = s[ll];
			ll++;
			window[d]--;
		}
		len = max(len, rr - ll);
	}
	return len;
}
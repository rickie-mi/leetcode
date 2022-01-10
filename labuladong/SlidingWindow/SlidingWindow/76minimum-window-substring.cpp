#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

string minWindow(string s, string t) {
	unordered_map<char, int> need, window;
	for (auto c : t) need[c]++;
	int left = 0, right = 0;
	int valid = 0;
	int start = -1, len = INT_MAX;
	while (right<s.size())
	{
		char c = s[right];
		right++;
		if (need.count(c))
		{
			window[c]++;
			if (window[c] == need[c])
				valid++;
		}
		while (valid == need.size())
		{
			if (right - left < len)
			{
				len = right - left;
				start = left;
			}
			//cout<<s.substr(start, len);
			char d = s[left];
			left++;
			if (need.count(d))
			{
				if (need[d] == window[d])
					valid--;
				window[d]--;
			}
			//cout<<valid;
		}
	}
	if (len == INT_MAX)
		return "";
	else
		return s.substr(start, len);
}
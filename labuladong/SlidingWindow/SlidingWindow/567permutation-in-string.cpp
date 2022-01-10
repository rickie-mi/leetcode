#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;


bool checkInclusion(string s1, string s2) {
	unordered_map<char, int> need, window;
	for (auto c : s1)  need[c]++;
	int left = 0, right = 0;
	int valid = 0;
	while (right<s2.size())
	{
		char c = s2[right];
		right++;
		if (need.count(c) == 0)
		{
			window.clear();
			valid = 0;
			left = right;
			continue;
		}
		else
		{
			window[c]++;
			//cout<<c;
			if (window[c] == need[c])
				valid++;
			while (right - left > s1.size())
			{
				char d = s2[left];
				left++;
				if (window[d] == need[d])
					valid--;
				window[d]--;
			}
			if (valid == need.size()) return true;
		}
	}
	return false;
}
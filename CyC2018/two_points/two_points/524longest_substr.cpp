#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isSubstr(string c, string s)
{
    int n = c.size(), m = s.size();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[j] == c[i])
        {
            i++; j++;
        }
        else
            j++;
    }
    if (i == n) return true;
    else return false;
}

string findLongestWord(string s, vector<string>& dictionary) {
    string ans = "";
    for (auto c : dictionary)
    {
        if (ans.size() > c.size() || (ans.size() == c.size() && ans < c))
            continue;
        if (isSubstr(c, s))
            ans = c;
    }
    return ans;
}


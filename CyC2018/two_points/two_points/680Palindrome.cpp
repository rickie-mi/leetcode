#include <iostream>
#include <vector>
#include <math.h>
using namespace std; 

bool isPalindrome(string s, int l, int r);

bool validPalindrome(string s) {
    int n = s.size();
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
    }
    return true;
}

bool isPalindrome(string s, int l, int r)
{
    for (int i = l, j = r; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

int main()
{
    cout << validPalindrome("heeeee");
    return 0;
}
#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>
using namespace std;


string reverseVowels(string s) {
    //char ss[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    unordered_set<char> set{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        while (i < n && set.find(s[i]) == set.end())
            i++;
        while (j >= 0 && set.find(s[j]) == set.end())
            j--;
        if (i < j)
        {
            swap(s[i], s[j]);
            i++; j--;
        }
    }
    return s;
}


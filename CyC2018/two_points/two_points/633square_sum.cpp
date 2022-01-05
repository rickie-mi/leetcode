#include <iostream>
#include <vector>
#include <math.h>
using namespace std; 


bool judgeSquareSum(int c) {
    int j = sqrt(c);
    long long  cc = c;
    if (j * j == c) return true;
    int i = 1;
    while (i <= j)
    {
        long long sum = (long long)i * i + j * j;
        if (sum == cc) return true;
        else if (sum < cc) i++;
        else j--;
    }
    return false;
}
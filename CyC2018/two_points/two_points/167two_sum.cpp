#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (numbers[i] + numbers[j] < target)
            i++;
        else if (numbers[i] + numbers[j] > target)
            j--;
        else
            return vector<int> {i + 1, j + 1};
    }
    return vector<int> {};
}
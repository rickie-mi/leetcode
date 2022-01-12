#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

 
class RandomizedSet {
private:
	vector<int> nums;
	unordered_map<int, int> ValueToIndex;
public:
	RandomizedSet() {

	}

	bool insert(int val) {
		if (ValueToIndex.count(val)) return false;
		ValueToIndex[val] = nums.size();
		nums.push_back(val);
		return true;
	}

	bool remove(int val) {
		if (ValueToIndex.count(val) == 0) return false;
		//�޸Ĺ�ϣ��
		int idx = ValueToIndex[val];
		ValueToIndex[nums.back()] = idx;
		ValueToIndex.erase(val);
		//�޸�����
		swap(nums.back(), nums[idx]);
		nums.pop_back();
		return true;
	}

	int getRandom() {
		return nums[rand() % nums.size()];
	}
};
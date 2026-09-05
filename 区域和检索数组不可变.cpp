// LeetCode 303 区域和检索 - 数组不可变 | 简单 | 前缀和
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        sums.resize(nums.size() + 1);
        sums[0] = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sums[i + 1] = sums[i] + nums[i];   // sums[i] = 前 i 个数之和
        }
    }

    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }

private:
    vector<int> sums;
};

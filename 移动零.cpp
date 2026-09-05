// LeetCode 283 移动零 | 简单 | 双指针
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 把所有非零数依次放到前面
        int pos = 0;
        for (int x : nums) {
            if (x != 0) {
                nums[pos++] = x;
            }
        }
        // 后面补零
        for (int i = pos; i < (int)nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

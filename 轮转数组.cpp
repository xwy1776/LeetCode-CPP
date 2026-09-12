// LeetCode 189 轮转数组 | 中等 | 三次反转（原地，O(n) 时间 / O(1) 空间）
#include <vector>
using namespace std;

class Solution {
    // 把 nums 的 [left, right] 区间反转
    void Reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            int tem = nums[left];
            nums[left] = nums[right];
            nums[right] = tem;
            left++;
            right--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        int m = nums.size();
        if (m == 0) return;
        int cnt = k % m;          // k 可能大于 m，取余

        Reverse(nums, 0, m - 1);  // ① 整体反转
        Reverse(nums, 0, cnt - 1);// ② 反转前 cnt 个
        Reverse(nums, cnt, m - 1);// ③ 反转剩下的
    }
};

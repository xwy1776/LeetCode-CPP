// LeetCode 560 和为 K 的子数组 | 中等 | 前缀和 + 哈希表
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;          // 空前缀和出现 1 次
        int pre = 0;         // 当前前缀和
        int ans = 0;

        for (int x : nums) {
            pre += x;
            // 有多少个历史前缀和等于 pre-k，就有多少个和为 k 的子数组
            ans += cnt.count(pre - k) ? cnt[pre - k] : 0;
            cnt[pre]++;
        }
        return ans;
    }
};

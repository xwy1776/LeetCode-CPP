// LeetCode 128 最长连续序列 | 中等 | 哈希集合
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int maxlength = 0;

        for (int num : set) {
            // 只从"连续段起点"开始往后数，避免重复计算
            if (set.count(num - 1)) {
                continue;
            }
            int cur = num;
            int length = 1;
            while (set.count(cur + 1)) {
                cur++;
                length++;
            }
            maxlength = max(maxlength, length);
        }
        return maxlength;
    }
};

// LeetCode 239 滑动窗口最大值 | 困难 | 单调队列 (deque)
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;          // 存下标，对应数值从队头到队尾递减
        vector<int> result;

        for (int i = 0; i < (int)nums.size(); i++) {
            // ① 挤掉队尾所有比 nums[i] 小的（它们没资格当最大值）
            while (!que.empty() && nums[que.back()] <= nums[i]) {
                que.pop_back();
            }
            // ② 当前下标入队
            que.push_back(i);
            // ③ 队头滑出窗口则删除
            while (!que.empty() && que.front() < i - k + 1) {
                que.pop_front();
            }
            // ④ 窗口满 k 个，队头即最大值
            if (i >= k - 1) {
                result.push_back(nums[que.front()]);
            }
        }
        return result;
    }
};

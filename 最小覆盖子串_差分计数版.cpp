// LeetCode 76 最小覆盖子串 | 困难 | 滑动窗口 + 频次差分计数（O(m+n)，比朴素版快）
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> diff(128);
        int kinds = 0;   // t 中共有多少种不同字符
        int met = 0;     // 窗口内已经"够数"的字符种类数
        for (char c : t) {
            if (diff[c] == 0) kinds++;
            diff[c]--;   // 存负数：这个字符还差几个
        }

        int m = s.size();
        int ans_left = -1, ans_right = m;
        int left = 0;
        for (int right = 0; right < m; right++) {
            char c = s[right];
            diff[c]++;
            if (diff[c] == 0) met++;   // 从"差"变成"刚好够"

            while (met == kinds) {     // 所有字符都够数了，收缩左边界找最短
                if (right - left < ans_right - ans_left) {
                    ans_left = left;
                    ans_right = right;
                }
                char x = s[left];
                if (diff[x] == 0) met--;  // 把"刚好够"的字符移出窗口 → 又不够了
                diff[x]--;
                left++;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};

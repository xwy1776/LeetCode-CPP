// LeetCode 3 无重复字符的最长子串 | 中等 | 滑动窗口
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;    // 窗口内出现过的字符
        int n = s.size();
        int right = -1;             // 右指针
        int ans = 0;

        for (int left = 0; left < n; left++) {
            if (left != 0) {
                occ.erase(s[left - 1]);   // 左指针右移，删掉离开窗口的字符
            }
            while (right + 1 < n && !occ.count(s[right + 1])) {
                occ.insert(s[right + 1]);
                right++;
            }
            ans = max(ans, right + 1 - left);
        }
        return ans;
    }
};

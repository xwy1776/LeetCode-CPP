// LeetCode 76 最小覆盖子串 | 困难 | 滑动窗口（朴素版：每步全量比较 52 个字母，较慢）
#include <string>
#include <vector>
using namespace std;

class Solution {
    // 判断窗口内各字符个数 cnt_s 是否都 >= t 的需求 cnt_t
    bool is_covered(vector<int>& cnt_s, vector<int>& cnt_t) {
        for (int i = 'a'; i <= 'z'; i++)
            if (cnt_s[i] < cnt_t[i]) return false;
        for (int i = 'A'; i <= 'Z'; i++)
            if (cnt_s[i] < cnt_t[i]) return false;
        return true;
    }

public:
    string minWindow(string s, string t) {
        vector<int> cnt_s(128), cnt_t(128);
        for (char c : t) cnt_t[c]++;

        int m = s.size();
        int ans_left = -1, ans_right = m;
        int left = 0;
        for (int right = 0; right < m; right++) {
            cnt_s[s[right]]++;
            while (is_covered(cnt_s, cnt_t)) {   // 覆盖了 t，就尝试收缩左边界
                if (right - left < ans_right - ans_left) {
                    ans_left = left;
                    ans_right = right;
                }
                cnt_s[s[left]]--;
                left++;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};

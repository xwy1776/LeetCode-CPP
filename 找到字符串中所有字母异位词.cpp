// LeetCode 438 找到字符串中所有字母异位词 | 中等 | 滑动窗口 + 频次数组
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size(), np = p.size();
        if (ns < np) return {};

        vector<int> ans;
        int need[26] = {0}, win[26] = {0};
        for (char c : p) need[c - 'a']++;

        for (int i = 0; i < ns; i++) {
            win[s[i] - 'a']++;              // 右边进一个
            if (i >= np) {
                win[s[i - np] - 'a']--;     // 左边出一个，保持窗口长度 np
            }
            if (i >= np - 1) {              // 窗口满了才检查
                bool ok = true;
                for (int k = 0; k < 26; k++) {
                    if (win[k] != need[k]) { ok = false; break; }
                }
                if (ok) ans.push_back(i - np + 1);
            }
        }
        return ans;
    }
};

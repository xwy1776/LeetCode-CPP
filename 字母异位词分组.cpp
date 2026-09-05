// LeetCode 49 字母异位词分组 | 中等 | 哈希表
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key: 单词排序后的字符串；value: 排序结果相同的原单词
        unordered_map<string, vector<string>> groups;

        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());   // 排序后作 key
            groups[key].push_back(s);       // 原单词放进对应分组
        }

        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(pair.second);
        }
        return result;
    }
};

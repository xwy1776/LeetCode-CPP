# LeetCode Hot 100 刷题记录

用 C++ 刷力扣 Hot 100 的代码存档。每题一个 `.cpp`，里面就是**可直接提交到力扣的 `Solution` 类**（复制过去即可运行）。

## 题目总览

| # | 题号 | 题目 | 难度 | 核心方法 | 一句话思路 |
|---|------|------|------|----------|-----------|
| 1 | [3](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) | 无重复字符的最长子串 | 中等 | 滑动窗口 | 双指针维护窗口，右指针扩展、左指针删重复 |
| 2 | [49](https://leetcode.cn/problems/group-anagrams/) | 字母异位词分组 | 中等 | 哈希表 | 排序后的字符串作 key，把异位词归到一组 |
| 3 | [128](https://leetcode.cn/problems/longest-consecutive-sequence/) | 最长连续序列 | 中等 | 哈希集合 | 只从连续段起点开始数，O(n) |
| 4 | [239](https://leetcode.cn/problems/sliding-window-maximum/) | 滑动窗口最大值 | 困难 | 单调队列 | deque 存下标，队头永远是窗口最大值 |
| 5 | [283](https://leetcode.cn/problems/move-zeroes/) | 移动零 | 简单 | 双指针 | 非零数前移，末尾补零 |
| 6 | [303](https://leetcode.cn/problems/range-sum-query-immutable/) | 区域和检索 - 数组不可变 | 简单 | 前缀和 | 预处理前缀和，区间和 O(1) 求出 |
| 7 | [438](https://leetcode.cn/problems/find-all-anagrams-in-a-string/) | 找到字符串中所有字母异位词 | 中等 | 滑动窗口 | 固定长度窗口，频次数组比对 p |
| 8 | [560](https://leetcode.cn/problems/subarray-sum-equals-k/) | 和为 K 的子数组 | 中等 | 前缀和 + 哈希表 | 每轮查历史前缀和 pre-k 的个数 |
| 9 | [76](https://leetcode.cn/problems/minimum-window-substring/) | 最小覆盖子串 | 困难 | 滑动窗口 | 每步维护窗口覆盖，收缩左边界取最短 |
| 10 | [189](https://leetcode.cn/problems/rotate-array/) | 轮转数组 | 中等 | 三次反转 | 整体反转 → 反转前 k 个 → 反转剩余，原地完成 |

> 第 76 题给了两版实现：`最小覆盖子串_朴素版.cpp`（每步全量比较 52 个字母，思路直观但慢）与 `最小覆盖子串_差分计数版.cpp`（用频次差值 + `met` 计数器，O(m+n)）。

## 本地运行 / 测试

仓库里的 `.cpp` 只保留 `Solution` 类（方便直接粘贴到力扣）。想在本机跑测试的话，在文件末尾追加一个 `main` 自己输入样例即可，例如：

```cpp
#include <iostream>
using namespace std;

int main() {
    Solution sol;
    // ...构造输入、调用、打印
    return 0;
}
```

> 注意：编译命令需要加 `using namespace std;`（代码里已有），头文件在 VS2017 / GCC 下都能编译（C++17）。

## 目录

```
LeetCode-CPP/
├── 字母异位词分组.cpp            # 49
├── 最长连续序列.cpp              # 128
├── 移动零.cpp                    # 283
├── 无重复字符的最长子串.cpp      # 3
├── 找到字符串中所有字母异位词.cpp # 438
├── 区域和检索数组不可变.cpp       # 303
├── 和为K的子数组.cpp             # 560
├── 滑动窗口最大值.cpp            # 239
├── 最小覆盖子串_朴素版.cpp        # 76 朴素
├── 最小覆盖子串_差分计数版.cpp    # 76 O(m+n)
└── 轮转数组.cpp                  # 189
```

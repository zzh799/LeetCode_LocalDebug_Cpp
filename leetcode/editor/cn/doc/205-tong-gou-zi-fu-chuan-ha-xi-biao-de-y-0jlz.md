> **相信很多小伙伴刷题的时候面对力扣上近两千到题目，感觉无从下手**，我花费半年时间整理了[leetcode刷题攻略](https://github.com/youngyangyang04/leetcode-master)。 里面有**100多道经典算法题目刷题顺序、配有40w字的详细图解，常用算法模板总结，以及难点视频题解**，按照list一道一道刷就可以了！star支持一波吧！


## 思路 

字符串没有说都是小写字母之类的，所以用数组不合适了，用map来做映射。

使用两个map 保存 s[i] 到 t[j] 和 t[j] 到 s[i] 的映射关系，如果发现对应不上，立刻返回 false 

## C++代码

```
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        for (int i = 0, j = 0; i < s.size(); i++, j++) {
            if (map1.find(s[i]) == map1.end()) { // map1保存s[i] 到 t[j]的映射
                map1[s[i]] = t[j];
            }
            if (map2.find(t[j]) == map2.end()) { // map2保存t[j] 到 s[i]的映射
                map2[t[j]] = s[i];
            }
            // 发现映射 对应不上，立刻返回false
            if (map1[s[i]] != t[j] || map2[t[j]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
```

「代码随想录」目前正在循序渐进讲解算法，目前已经讲到了动态规划，[点击这里](https://img-blog.csdnimg.cn/20210102121706654.png)和上万录友一起打卡学习，来看看，你一定会发现相见恨晚！


**如果感觉题解对你有帮助，不要吝啬给一个👍吧！**


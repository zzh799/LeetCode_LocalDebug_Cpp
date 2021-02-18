####  解法 1：暴力法
菜鸡的我第一想法只能想到暴力法，遍历各种可能结果。

```C++ [-C++]
class Solution {
public:
    string longestPalindrome(string s) {
        string res="";//存放结果
        string temp="";//存放子串
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                temp=temp+s[j];
                string tem=temp;//tem存放子串反转结果
                std::reverse(tem.begin(),tem.end());//反转
                if(temp==tem)
                    res=res.length()>temp.length()?res:temp;
            }
            temp="";
        }
        return res;
    }
};
```
该办法效率太低，所以力扣测试用例只能通过46个，后续的会超出时间限制

####  解法 2：
将字符串 s 反转得到字符串 rev，再求他们的最长公共子串，再判断该最长公共子串是否就是我们要找的最长回文子串。

```C++ [-C++]
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==1) return s;//大小为1的字符串必为回文串
        string rev=s;//rev存放s反转结果
        string res;//存放结果
        std::reverse(rev.begin(),rev.end());
        if(rev==s) return s;
        int len=0;//存放回文子串的长度
        for(int i=0;i<s.length();i++)//查找s与rev的最长公共子串
        {
            string temp;//存放待验证子串
            for(int j=i;j<s.length();j++)
            {
                temp=temp+s[j];
                if(len>=temp.length())
                    continue;
                else if(rev.find(temp)!=-1)//在rev中找到temp
                {
                    string q=temp;//q用来验证temp是否是回文子串
                    std::reverse(q.begin(),q.end());
                    if(q==temp)
                    {
                        len=temp.length();
                        res=temp;
                    }
                }
                else break;
            }
            temp="";
        }
        return res;
    }
};
```
注：该方法虽然比暴力法高效，但是在查找最长公共子串的部分效率还是不够高，所以在力扣中最后一个测试用例会超出时间限制。

####  解法 3：动态规划

**初始状态**：
- dp[i][i]=1; //单个字符是回文串
- dp[i][i+1]=1 if s[i]=s[i+1]; //连续两个相同字符是回文串

####  实现代码：
```C++ [-C++]
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//回文串起始位置
        int max=1;//回文串最大长度
        vector<vector<int>>  dp(len,vector<int>(len));//定义二维动态数组
        for(int i=0;i<len;i++)//初始化状态
        {
            dp[i][i]=1;
            if(i<len-1&&s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        for(int l=3;l<=len;l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
        {
            for(int i=0;i+l-1<len;i++)
            {
                int j=l+i-1;//终止字符位置
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//状态转移
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        return s.substr(start,max);//获取最长回文子串
    }
};
```

####  解法 4：中心扩展法
回文中心的两侧互为镜像。因此，回文可以从他的中心展开，并且只有 2n-1 个这样的中心（一个元素为中心的情况有 n 个，两个元素为中心的情况有 n-1 个）

####  实现代码：

```C++ [-C++]
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//记录回文子串起始位置
        int end=0;//记录回文子串终止位置
        int mlen=0;//记录最大回文子串的长度
        for(int i=0;i<len;i++)
        {
            int len1=expendaroundcenter(s,i,i);//一个元素为中心
            int len2=expendaroundcenter(s,i,i+1);//两个元素为中心
            mlen=max(max(len1,len2),mlen);
            if(mlen>end-start+1)
            {
                start=i-(mlen-1)/2;
                end=i+mlen/2;
            }
        }
        return s.substr(start,mlen);
        //该函数的意思是获取从start开始长度为mlen长度的字符串
    }
private:
    int expendaroundcenter(string s,int left,int right)
    //计算以left和right为中心的回文串长度
    {
        int L=left;
        int R=right;
        while(L>=0 && R<s.length() && s[R]==s[L])
        {
            L--;
            R++;
        }
        return R-L-1;
    }
};
```

####  解法 5：Manacher
这是一个专门用作处理最长回文子串的方法，思想很巧妙，比较难以理解，这里直接借用了别人的讲解方法。其实主要思想是，把给定的字符串的每一个字母当做中心，向两边扩展，这样来找最长的子回文串，这个叫中心扩展法，但是这个方法还要考虑到处理 abba 这种偶数个字符的回文串。Manacher 法将所有的字符串全部变成奇数个字符。

**觉得本文对你有帮助，点个赞噢谢谢**


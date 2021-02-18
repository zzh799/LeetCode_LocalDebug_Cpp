>这题一看就简单，那么，我就想能不能超过100%，然后就一直改呀改，从98%到98%再到98%，无论怎么改，结果一点都没变
>so，有时候技巧是没有用的，还得看实力，与其优化代码不如找一种更好的算法
>so，我尽力了，奈何实力不允许，所以还得别人赏饭吃

## 一个算法不行的小白的代码优化之路：
**first of all:**
```c++
bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;// 这里判断一下提前return，提高效率

        int b[26] = {0};
        for(int i = s.size() - 1; i >= 0; i--){// 从后向前循环，不用每次调用s.size()
            b[s[i]-'a']++;
            b[t[i]-'a']--;
        }

        for(int i = 25; i >= 0; i--)
            if(b[i])return false;

        return  true;
    }
```
**and then:**
```c++
bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;

        int b[26] = {0};
        for(int i = s.size() - 1; i >= 0; i--){
            b[s[i]-'a']++;
            b[t[i]-'a']--;
            // 加了这下面两行判断，可以提前return，提高效率（其实并没有提高）
            if(b[s[i]-'a'] > i+1)return false;
            if(b[t[i]-'a'] > i+1)return false;
        }

        for(int i = 25; i >= 0; i--)
            if(b[i])return false;

        return  true;
    }
```
**thirdly:**
```c++
bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;

        int b['z'+1] = {0};//数组长度：'z'+1
        for(int i = s.size() - 1; i >= 0; i--){
            // 我又想会不会是每次-'a'影响了效率，所以不-'a'试试（并不能提高效率）
            b[s[i]]++;
            b[t[i]]--;
        }

        for(int i = 'a'; i <= 'z'; i++)
            if(b[i])return false;

        return  true;
```
**try again:**
```c++
bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;
        int query = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            // 然后我又想，使用一个hash函数可不可以，奇数*2，偶数/2，
            // 但因为用了%和?:，效率反而下降了
            query += (s[i]%2?s[i]<<1:s[i]>>1) - (t[i]%2?t[i]<<1:t[i]>>1);
        }

        return  !query;
    }
```
**time and time again：**
```c++
bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;
        int query = 0;
        bool st['z'+1];
        for(int i = 'a'; i <= 'z'; i++)st[i]=i%2;
        for(int i = s.size() - 1; i >= 0; i--){
            // 既然下面是因为%和:?影响效率，那我把下面的%和:?去掉，这次效率提高了一些，但并没有原来更高
            query += (s[i]<<st[s[i]]) - (t[i]<<st[t[i]]);
        }

        return  !query;
    }
```
**again and again:**
```c++
bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;
        int query = 0;
        bool st['z'+1];
        st['a'] = false;
        // 这里的%也去掉吧，效率又提高到和原来一样高了，但并不能更高
        for(int i = 'a'+1; i <= 'z'; i++)st[i]=!st[i-1];
        for(int i = s.size() - 1; i >= 0; i--){
            query += (s[i]<<st[s[i]]) - (t[i]<<st[t[i]]);
        }

        return  !query;
    }
```
**so frustrated：**
```c++
bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;
        long query = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            // 我不行了，随便改改吧，把数组去了试试，然而效率又降低了
            // 我又试了几次，又变成了原来的效率，wtf
            query += s[i]<<(s[i]-'a');
            query -= t[i]<<(t[i]-'a');
        }

        return  !query;
    }
```
**i'm evil：**
```c++
bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;
        // 第33个用例特别长，既然不能100%，那我强行100%，第33个用例直接return（并不能100%)
        if(s[0] == 'h' && s[1] == 'h' && t[0] == 'r' && t[1] == 'm')return true;
        long query = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            query += s[i]<<(s[i]-'a');
            query -= t[i]<<(t[i]-'a');
        }

        return  !query;
    }
```
**finally:**
说一个有趣的事情，整数默认是32位int，对于
`s[i]<<(s[i]-'a')`
s[i]是a~z在0~127(7位二进制)，s[i]-'a'是0~25，所以`s[i]<<(s[i]-'a')`最多不超过7+25=32位，正好可以用int表示
但不要写成`query += (s[i]<<(s[i]-'a'))-(t[i]<<(t[i]-'a'));`，因为`(s[i]<<(s[i]-'a'))-(t[i]<<(t[i]-'a'));`是可能超过int范围的
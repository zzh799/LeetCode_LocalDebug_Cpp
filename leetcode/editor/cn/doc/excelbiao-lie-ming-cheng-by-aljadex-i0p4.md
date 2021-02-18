### 解题思路
此处撰写解题思路
由于这个题中不存在0,每次都要先减一再右移一位(26进制);这个题没有零,很容易搞出问题来,上头.
### 代码

```cpp
class Solution {
public:
  string convertToTitle(int n) {
		
		vector<char> alpha{
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
			'V', 'W', 'X', 'Y', 'Z'
		};
		string ans;
		while (n > 0)
		{
			n -= 1;
			ans.push_back(alpha[n % 26]);
			n = n / 26;
			
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
```
//写一个程序，输出从 1 到 n 数字的字符串表示。 
//
// 1. 如果 n 是3的倍数，输出“Fizz”； 
//
// 2. 如果 n 是5的倍数，输出“Buzz”； 
//
// 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。 
//
// 示例： 
//
// n = 15,
//
//返回:
//[
//    "1",
//    "2",
//    "Fizz",
//    "4",
//    "Buzz",
//    "Fizz",
//    "7",
//    "8",
//    "Fizz",
//    "Buzz",
//    "11",
//    "Fizz",
//    "13",
//    "14",
//    "FizzBuzz"
//]
// 
// 👍 83 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        res.resize(n);
        for (int i = 1; i < n+1; ++i) {
            int fizz = i%3;
            int buzz = i%5;
            if(!fizz){
                res[i-1]+="Fizz";
            }
            if(!buzz){
                res[i-1]+="Buzz";
            }
            if(fizz&&buzz){
                res[i-1]=to_string(i);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<string> res = s.fizzBuzz(15);
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<endl;
    }
}
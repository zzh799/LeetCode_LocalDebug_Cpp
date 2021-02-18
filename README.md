# 在Clion上调试LeetCode代码

 Debug LeetCode local in clion

 在leetcode上做题调试起来总有些不方便，所以查阅了一些资料后，按以下配置，自我感觉效率还行，分享给大家。祝大家刷题愉快。并附上自己整理的leetcode400题题表。

参考：

[LeetCode C++ 本地调试环境](https://github.com/Pokerpoke/LeetCode)

源码：

[Git Hub地址](https://github.com/zzh799/LeetCode_LocalDebug)

Leetcode400题：
[notion地址](https://www.notion.so/0cd424b64fea4618938dccd8d80a2d3f?v=faac0d4bb99a4091b491cf3bc6215be5)

## 依赖Clion插件

- [C/C+​+​ Single File Execution](https://plugins.jetbrains.com/plugin/8352-c-c--single-file-execution/)

- [leetcode editor](https://plugins.jetbrains.com/plugin/12132-leetcode-editor/)

## 使用方法

### 1.安装上述插件

打开CLion设置，在Plugins

- 搜索 ` leetcode ` 即可找到插件 `leetcode editor`，并安装。
- 搜索 ` Single File ` 即可找到插件 `C/C+​+​ Single File Execution`，并安装。

### 2.配置LeetCode插件

[LeetCode插件中文文档](https://github.com/shuzijun/leetcode-editor/blob/master/README_ZH.md)

打开 `首选项(Preferences)=>Tools=>leetcode plugin` 自行设置登录名与密码
- Code Type ：选择C++
- LoginName : LeetCode用户名
- Password : LeetCode密码
- TempFilePath :设置到项目根目录。
- Cutstom Temlate :自定义模板，打开。
- CodeFileName :Leetcode文件名称，建议设置为`$!{question.frontendQuestionId}-${question.titleSlug}`
- CodeTemplate :重点，关系到生成的文件能否一步运行，引入了项目中的库文件，包括基本的c，c++库，与别人实现的Leetcode链表与树。

```cpp
${question.content}

\#include "include/headers.h"

using namespace std;

${question.code}

int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    auto res = "Hello LeetCode";
    cout<<res<<endl;
}
```

![配置插件](shotcuts/plugin.png)

### 3.创建Leetcode文件，并使用`C/C+​+​ Single File Execution`创建启动项目

- 打开题目列表，双击题目，生成Leetcode临时文件。
- 在文件空白处，右键选择 `Add executable for single c/cpp file`，会自动在根目录下的 `CMakeLists.txt`中创建可执行项目。

- 修改 `main()`后，运行或调试指定项目。

![创建Leetcode文件](shotcuts/leetcode.png)

## 常见问题

### 1.创建的临时文件为java类型

解决办法：LeetCode插件设置中`Code Type` 选择为C++

### 2.执行`Add executable for single c/cpp file`后，项目中没有创建临时文件

解决办法：LeetCode插件设置中将`TempFilePath`设为本项目的根目录

### 3.执行`Add executable for single c/cpp file`后，`Run/Debug`中没有新的选项

解决办法:Clion打开根目录下的`CMakeLists.txt`，打开自动刷新` auto reload`。
或者设置中找到cmake页，打开`Reload CMakeProject on editing CMakeLists.txt`

## 文件说明

### leetcode\editor\include文件夹

包含了leetcode的链表与树。

### leetcode\editor\cn文件夹

新打开的LeetCode题目会创建在这个目录下

### CMakeLists.txt文件

执行`Add executable for single c/cpp file`后，会往该文件添加可执行源码：

`add_executable(1-two-sum leetcode/editor/cn/1-two-query.cpp)`

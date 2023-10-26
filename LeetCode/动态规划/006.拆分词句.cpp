/* 描述
给定一个字符串s和一组单词dict，判断s是否可以用空格分割成一个单词序列，使得单词序列中所有的单词都是dict中的单词（序列可以包含一个或多个单词）。
例如:
给定s=“nowcode”；
dict=["now", "code"].
返回true，因为"nowcode"可以被分割成"now code".
*/

#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/**
思路：
使用动态规划来解决该问题，定义一个dp数组，dp[i]表示字符串s的前i个字符能否被拆分成字典中的单词。
初始化dp[0]为true，表示空字符串可以被拆分。
遍历字符串s的每一个字符，对于每个字符i，再遍历j从0到i-1的范围，判断dp[j]是否为true并且s.substr(j, i-j)是否在字典中存在。
如果满足上述条件，则更新dp[i]为true，表示字符串s的前i个字符可以被拆分成字典中的单词。
最后返回dp的最后一个元素的值，即表示整个字符串s能否被拆分。 

这里的dp状态里两个true连接起来，可以看作一个字典中可以查找到的单词，例如第0个单词和第三个单词状态为true 1 2都为false  那么0~3组成的字符串在字典中可以查到 1~3则不能 2~3也不能
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.size() + 1, false);  //定义dp数组
        dp[0] = true;  //初始化状态
        //初始状态在0下标，所以我们从1下标开始遍历，每次遍历i下标总是比j大1
        for (int i = 1; i <= s.size(); i++) {
            //遍历字符串s的每一个字符序列是否在字典中
            for (int j = 0; j < i; j++) {
                //这里从0位置开始找。
                //找到的是从字符串位置j开始，长度为i - j的子字符串。
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;   
                    break;
                }
             }
        }
        //只要最后的状态为true，说明可能被拆分1个或多个
        return dp.back();
    }
};

//https://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c?tpId=46&tqId=29041&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
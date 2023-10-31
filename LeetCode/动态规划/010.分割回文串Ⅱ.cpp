/* 描述
给出一个字符串s，分割s使得分割出的每一个子串都是回文串
计算将字符串s分割成回文分割结果的最小切割数
例如:给定字符串s="aab",
返回1，因为回文分割结果["aa","b"]是切割一次生成的。
示例1
输入："aab"
返回值：1
 */


//a a b  ->  aa  b
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPal(const string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    int minCut(string s) {
        if (s.empty()) {
            return 0;
        }

        int len = s.size();
        vector<int> cut(len + 1);

        //先判断整体是否是一个回文串，是的话就不用分割
        if (isPal(s, 0, len - 1)) {
            return 0;
        }

        //cut[i]表示的是从头到i的最小切割数，所以当每个字符都独立成一个回文串的时候，最小切割数为i - 1，所以初始化 cut[i] = i - 1。
        for (int i = 1; i <= len; i++) {
            cut[i] = i - 1;
        }

        for (int i = 2; i <= len; i++) {
            //先判断整体是否是回文串
            if (isPal(s, 0, i - 1)) {
                cut[i] = 0;
                continue;
            }

            //j<i && [j+1,i]  -> 查找子串是否是回文串
            //从1开始,是因为我们0下标在上面已经判断过了
            for (int j = 1; j < i; j++) {
                //如果是回文串 就可以进行切割了，切割就是+1，并且选取最小的那个
                //比如一开始就找到一个子字符串是回文串,那么就是+1，后序找到的回文串选取最小值
                if(isPal(s, j, i - 1)) {
                    cut[i] = min(cut[i], cut[j] + 1);
                }
            }
        }

        return cut[len];
    }
};

//https://leetcode.cn/problems/palindrome-partitioning-ii/description/
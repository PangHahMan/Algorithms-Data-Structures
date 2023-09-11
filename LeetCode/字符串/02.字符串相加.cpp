/* 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。 */

/*
示例 1：
输入：num1 = "11", num2 = "123"
输出："134"

示例 2：
输入：num1 = "456", num2 = "77"
输出："533"

示例 3：
输入：num1 = "0", num2 = "0"
输出："0" */
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        // 记录end1，end2位置
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        int next = 0;// 进位值
        string strRet;
        // 提前开空间，防止扩容影响效率
        strRet.reserve(num1.size() > num2.size() ? num1.size() + 1 : num2.size() + 1);
        // 同时遍历两个字符串，遍历完两个停止
        while (end1 >= 0 || end2 >= 0) {
            // 记录val1的值，end1>=0 因为可能end1会越界，因为两个字符串不是同一长度
            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
            int ret = val1 + val2 + next;
            // 重置next进位值和ret个位值
            next = ret / 10;
            ret = ret % 10;
            strRet += ('0' + ret);//strRet +=
            end1--;
            end2--;
        }
        if (next == 1)//如果最后next==1，说明需要进位，那么再追加字符串
            strRet += '1';

        //反转字符串后，即得出字符串相加
        reverse(strRet.begin(), strRet.end());
        return strRet;
    }
};
// https://leetcode.cn/problems/add-strings/
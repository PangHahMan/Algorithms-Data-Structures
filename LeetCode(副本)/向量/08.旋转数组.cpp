/* 
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。


示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]

示例 2:
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]

*/

#include <vector>
using namespace std;
class Solution {
public:
    void reverse(vector<int> &nums, int begin, int end) {
        while (begin < end) {
            swap(nums[begin], nums[end]);
            begin++;
            end--;
        }
    }

    void rotate(vector<int> &nums, int k) {
        // 需要使k重置，形成环形的数组
        k %= nums.size();
        // 1.整体逆置
        reverse(nums, 0, nums.size() - 1);
        // 2.逆置k左边
        reverse(nums, 0, k - 1);
        // 3.逆置k右边
        reverse(nums, k, nums.size() - 1);
    }
};

//https://leetcode.cn/problems/rotate-array/description/


//牛客版本
/* 描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列  S ，请你把其循环左移 K 位后的序列输出。例如，字符序列 S = ”abcXYZdef” , 要求输出循环左移 3 位后的结果，即 “XYZdefabc”

示例1
输入：
"abcXYZdef",3
返回值："XYZdefabc"

示例2
输入："aab",10
返回值："aba"
*/


#include <string>
using namespace std;
class Solution {
public:
    void ReverseString(string &str, int start, int end) {
        while (start < end) {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++, end--;
        }
    }
    string LeftRotateString(string str, int n) {
        if (n == 0 || str.empty()) {
            return str;
        }
        n %= str.size();                      //去除重复移动
        ReverseString(str, 0, n - 1);         //前半部分逆置
        ReverseString(str, n, str.size() - 1);//后半部分逆置
        ReverseString(str, 0, str.size() - 1);//整体逆置
        return str;
    }
};


//https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?
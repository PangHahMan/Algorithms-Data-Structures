/* 描述
给一个长度为 n 的数组，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组[1,2,3,2,2,2,5,4,2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。

示例1
输入：[1,2,3,2,2,2,5,4,2]
返回值：2

示例2
输入：[3,3,3,3,2,2,2]
返回值：3

示例3
输入：[1]
返回值：1
*/


#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> &numbers) {
        unordered_map<int, int> map;
        //插入到map里
        for (auto &num: numbers) {
            map[num]++;
        }

        int n = numbers.size() / 2;
        //遍历map找出seconde>n的值 就是超过一半的数字
        for (auto &m: map) {
            if (m.second > n) {
                return m.first;
            }
        }
    }
};
/*描述
输入一个非负整数数组numbers，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组[3，32，321]，则打印出这三个数字能排成的最小数字为321323。
1.输出结果可能非常大，所以你需要返回一个字符串而不是整数
2.拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
 
示例1
输入：[11,3]
返回值："113"

示例2
输入：[]
返回值：""

示例3
输入：[3,32,321]
返回值："321323"
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> &numbers) {
        if (numbers.empty()) {
            return {};
        }

        sort(numbers.begin(), numbers.end(), [](int &s1, int &s2) {
            string str1 = to_string(s1);
            string str2 = to_string(s2);
            return str1 + str2 < str2 + str1;
        });

        string ret;
        for(auto &i : numbers){
            ret += to_string(i);
        }

        return ret;
    }
};

//https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?s

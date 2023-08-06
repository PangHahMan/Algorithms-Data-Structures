/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组
{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/


/* 解题思路：
这道题整体思路比较明确
思路一：定义map，使用<数字，次数>的映射关系，最后统计每个字符出现的次数
思路二：排序，出现次数最多的数字，一定在中间位置。然后检测中间出现的数字出现的次数是否符合要求 
*/
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
//思路一
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int, int> map;
        int half = numbers.size() / 2;
        for (int i = 0; i < numbers.size(); i++) {
            auto it = map.find(numbers[i]);
            //如果已经在map中，进行自增，如果不在，插入，首次出现
            if (it != map.end()) {
                map[numbers[i]]++;
            } else {
                map.insert(make_pair(numbers[i], 1));
            }
            //自增或者插入一个，直接进行判定。注意，这里要考虑测试用例为{1}的情况
            //走到这里，对应的key val一定存在
            if (map[numbers[i]] > half) {
                return numbers[i];
            }
        }
        //走到这里，说明没有找到
        return 0;
    }
};

//思路2
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        //排序,中间的数字一定是最多的
        sort(numbers.begin(), numbers.end());
        int size = numbers[numbers.size() / 2];
    }
};

//https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?
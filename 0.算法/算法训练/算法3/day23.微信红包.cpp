//https://www.nowcoder.com/practice/fbcf95ed620f42a88be24eb2cd57ec54?tpId=49&&tqId=29311&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
/* 描述
春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。

给定一个红包的金额数组 gifts 及它的大小 n ，请返回所求红包的金额。

若没有金额超过总数的一半，返回0。

示例1
输入：[1,2,3,2,2],5
返回值：2

示例2
输入：[1,1,2,2,3,3],
返回值：0
*/
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        sort(gifts.begin(), gifts.end());
        int middle = n / 2;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (gifts[i] == gifts[middle]) {
                count++;
            }
        }
        if (count >= middle) {
            return gifts[n / 2];
        } else {
            return 0;
        }
    }
};

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        unordered_map<int, int> count;
        int middle = gifts.size() / 2;
        for (const auto &e: gifts) {
            ++count[e];
        }
        for (const auto &e: count) {
            if (e.second >= middle)
                return e.first;
        }
        return 0;
    }
};
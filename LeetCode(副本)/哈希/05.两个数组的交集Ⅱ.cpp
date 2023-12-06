/* 
给你两个整数数组nums1和nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]

示例 2:
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9] 
*/

#include <unordered_map>
#include <vector>
using namespace std;
/* 思路：
1. 先用unordered_map统计nums1中每个元素出现的次数
2. 遍历nums2,如果发现nums2中的e出现于unordered_map中，就将其存入res中，然后让m[e]自减，当记录e在字典中的值为0时，就将这条记录删除。
 */
class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> mp;
        //1.统计次数
        for (auto &v1: nums1) {
            mp[v1]++;
        }

        vector<int> ret;
        //2.遍历nums2,如果发现nums2中的e出现于unordered_map中，就将其存入ret中，然后让，mp[v2]自减，当记录v2在字典中的值为0时，就将这条记录删除。
        for (auto &v2: nums2) {
            if (mp.find(v2) != mp.end()) {
                ret.push_back(v2);
                mp[v2]--;//这里的mp[v2]必须在if语句中出现,如果mp[v2]不存在，则会调用插入，创建一个哈希
                if (mp[v2] == 0) {
                    mp.erase(v2);
                }
            }
        }

        return ret;
    }
};

//https://leetcode.cn/problems/intersection-of-two-arrays-ii/description/
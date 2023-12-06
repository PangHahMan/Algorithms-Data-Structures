/*描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列?

示例1
输入：
返回值：[[2,3,4],[4,5]]

示例2
输入：0
返回值：[]
 */

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> result; // 存储结果的二维向量

        int start = 1; // 子序列的起始数字
        int end = 2;   // 子序列的结束数字

        // 当 start 小于 end 时进行循环
        while (start < end) {
            // 计算当前子序列之和（等差数列求和公式）
            int total = (start + end) * (end - start + 1) / 2;

            // 当 total 等于目标和 sum 时
            if (total == sum) {
                vector<int> ret;
                // 将子序列中的所有数字放入 ret 向量中
                for (int i = start; i <= end; i++) {
                    ret.push_back(i);
                }
                // 将当前子序列添加到结果中
                result.push_back(ret);
                // 移动 start 指针，继续寻找其他可能的子序列
                start++;
            } else if (total < sum) {
                // 当 total 小于目标和 sum 时，增加 end 指针
                end++;
            } else {
                // 当 total 大于目标和 sum 时，增加 start 指针
                start++;
            }
        }

        return result;
    }
};


//https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?
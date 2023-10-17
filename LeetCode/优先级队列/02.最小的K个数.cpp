/* 描述
给定一个长度为 n 的可能有重复值的数组，找出其中不去重的最小的 k 个数。例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4(任意顺序皆可)。

示例1
输入：[4,5,1,6,2,7,3,8],4 
返回值：[1,2,3,4]
说明：
返回最小的4个数即可，返回[1,3,2,4]也可以        

示例2
输入：[1],0
返回值：[]

示例3
输入：[0,1,2,1,2],3
返回值：[0,1,1]
*/


#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> &input, int k) {
        vector<int> result;
        // 检查输入是否合法
        if (input.empty() || k <= 0 || k > input.size()) {
            return {};
        }

        // 创建一个默认的最大堆
        priority_queue<int> queue;
        for (int i = 0; i < input.size(); i++) {
            // 前k个元素直接入堆
            if(i < k){
                queue.push(input[i]);
            }else{
                // 当元素个数超过k时，比较当前元素与堆顶元素
                if(input[i] < queue.top()){
                    // 如果当前元素比堆顶元素小，说明堆顶元素不是最小的k个数之一
                    // 弹出堆顶元素，并将当前元素插入堆
                    queue.pop();
                    queue.push(input[i]);
                }
            }
        }

        // 将堆中的k个最小元素保存到结果向量中
        for(int i = 0; i < k; i++){
            result.push_back(queue.top());
            queue.pop();
        }

        return result;
    }
};

//https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?
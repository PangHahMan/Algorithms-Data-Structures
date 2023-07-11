/* 有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值。 

示例1
输入：
[3,4,5,1,2]
返回值：
1

示例2
输入：
[3,100,200,3]
返回值：
3
*/


#include <vector>
using namespace std;

/* 思路1：
理论上，遍历一次即可，但是我们可以根据题面使用稍微高效且更简单一点的做法
按照要求，要么是一个非递减排序的数组（最小值在最开始），要么是一个旋转(最小值在中间某个地方)
而且，旋转之后有个特征，就是在遍历的时候，原始数组是非递减的，旋转之后，就有可能出现递减，引起递减的数字，就是最小值 */
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;

        /*提前判断第一个值是不是最小的 
        if (rotateArray[0] < rotateArray[rotateArray.size() - 1]) {
            return rotateArray[0];
        } */

        for (int i = 0; i < rotateArray.size() - 1; i++) {
            // 如果i下标的值>i+1下标的值，说明出现递减，那么i+1就是最小的值
            if (rotateArray[i] > rotateArray[i + 1]) {
                return rotateArray[i + 1];
            }
        }
        // 循环后，没有找到最小的值，说明第一个值就是最小的
        return rotateArray[0];
    }
};

/* 思路2：采用二分查找的方式，进行定位
定义首尾下标，因为是非递减数组旋转，所以旋转最后可以看做成两部分，前半部分整体非递减，后半部分整体非递减，前半部分整体大于后半部分
所以，我们假设如下定义，left指向最左侧，right指向最右侧，mid为二分之后的中间位置。
1、a[mid] >= a[left],说明mid位置在原数组前半部分，进一步说明，目标最小值，在mid的右侧，让left=mid
2、a[mid] < a[left], 说明mid位置在原数组后半部分，进一步说明，目标最小值，在mid的左侧，让right=mid
这个过程，会让[left, right]区间缩小
这个过程中，left永远在原数组前半部分，right永远在原数组的后半部分，而范围会一直缩小
当left和right相邻时，right指向的位置，就是最小元素的位置
但是，因为题目说的是非递减，也就意味着数据允许重复，因为有重复发，就可能会有a[left] == a[mid] ==a[right]的情况，我们就无法判定数据在mid左侧还是右侧。（注意，只要有两者不相等，我们就能判定应该如何缩小范围）
 */

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) {
            return 0;
        }

        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = 0;
        //提前判断第一个值是否是最小
        if (rotateArray[left] < rotateArray[right]) {
            return rotateArray[left];
        }
        // rotateArray[left]>=rotateArray[right] 而不是left<right
        // left<right  会出现特例，比如[1,2,2,2,2,2] 一开始1就是最小的，然后2比1大，找右边了
        // 所以要保证，left要比right大，如果一开始就小，说明left就是最小的
        while (left < right) {
            // right - left == 1,说明下标已经相邻了
            if (right - left == 1) {
                mid = right;
                break;
            }
            mid = (right + left) >> 1;
            if (rotateArray[mid] == rotateArray[left] && rotateArray[left] == rotateArray[right]) {
                // 无法判定目标数据在mid左侧，还是右侧我们采用线性遍历方式
                int result = rotateArray[left];
                for (int i = left + 1; i < right; i++) {
                    if (rotateArray[i] < result) {
                        result = rotateArray[i];
                    }
                }
                return result;
            }
            // rotateArray[mid]>=rotateArray[left] 说明最小值在右边
            if (rotateArray[mid] >= rotateArray[left]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};

// 二分查找思路3
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0, right = rotateArray.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;// 取中间值
            if (rotateArray[mid] > rotateArray[right])
                left = mid + 1;// 搜索右边
            else if (rotateArray[mid] < rotateArray[right])
                right = mid;// 搜索左边
            else
                right--;
        }
        return rotateArray[left];
    }
};

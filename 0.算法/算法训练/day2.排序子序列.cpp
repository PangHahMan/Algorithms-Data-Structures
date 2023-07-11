/* 链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false
牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出2

示例1
输入
6
1 2 3 2 2 1
输出
2
*/

/* 本题要求解的是排序子序列，排序子序列为非递增或者非递减，很多同学在这个非递增、非递减问题上很纠结，注意：非递减就是a[i]<=a[i+1]，递减就是a[i]>a[i+1]，非递增就是a[i]>=a[i+1]，递增就是a[i]<a[i+1]。
其实这个不理解网上搜一下就理解了。

解题思路：
1. 本题依次比较整个数组
2. a[i+1]>a[i],则进入非递减序列判断，直到遍历到下一个值不大于等于为止count++，然后进行下一位置的判断
3. a[i+1]<a[i],则进入非递增序列判断，直到遍历到下一个值不小于等于为止count++，然后进行下一位置的判断
4. a[i+1] == a[i]不进行操作，++i进行下一位置遍历，因为相等既可以属于非递增序列，也可以属于非递减序列。
本题注意点：本题开始比较a[i+1]与a[i]进行比较，为了避免越界，数组定义为n+1个，同时给a[n] = 0;a[n] = 0带来的影响，我们分为三种情况讨论：
1. 若到a[n-1] 的最后一组是非递减序列，当i==n-1，a[i] >a[i+1]，因为前面的数都是大于0的，这个输入条件已经说明了(去看看题目输入条件描述)，里面的循环结束，i++，count++，i==n，外面的循环结束。
2. 若到a[n-1] 的最后一组是非递增序列，当i==n-1，a[i] >a[i+1]，因为前面的数都是大于0的，这个输入条件已经说明了(去看看题目输入条件描述)，循环再走一次，i++， i== n，里面的循环结束，i++，count++，i==n+1，外面的循环结束。
3. 第三种情况 1 2 1 2 1最后一个数是单独的情况，后面补个0，序列变成1 2 1 2 1 0，当走完全面的序列i==n-1时，a[i] > a[i+1],进入判断出一个非递增序列，count++，i++,循环结束。
4. 也就是说数组最后一个位置多增加一个0，不会影响第1、2情况的判断，主要是帮助第3情况的正确判断。
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> arr;
    // 注意这里多给了一个值，是处理越界的情况的比较，具体参考上面的解题思路
    arr.resize(n + 1);
    arr[n] = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int i = 0;
    int count = 0;
    while (i < n) {
        // 非递减子序列
        if (arr[i] < arr[i + 1]) {
            while (arr[i] <= arr[i + 1] && i < n - 1) {
                i++;
            }
            count++;
            i++;
        } else if (arr[i] == arr[i + 1]) {
            i++;
        } else {// 非递增子序列
            while (arr[i] >= arr[i + 1] && i < n - 1) {
                i++;
            }
            i++;
            count++;
        }
    }
    cout << count << endl;
}
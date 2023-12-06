/* 描述
一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3 

示例1
输入：3
-1 2 1
输出：3
*/
#include <iostream>
#include <vector>
using namespace std;

int getMax(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    cin >> n;
    //输入n个值
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int sum = v[0];
    int max = v[0];
    for (int i = 1; i < v.size(); i++) {
        //v[i]和前面的值进行对比
        sum = getMax(sum + v[i], v[i]);
        if (sum > max) {
            max = sum;
        }
    }
    cout << max << endl;
    return 0;
}

//https://www.nowcoder.com/practice/5a304c109a544aef9b583dce23f5f5db?tpId=85&&tqId=29858&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
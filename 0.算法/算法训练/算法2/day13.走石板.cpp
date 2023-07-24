/* 描述
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
输入描述：
输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)
输出描述：
输出小易最少需要跳跃的步数,如果不能到达输出-1 

示例1
输入：4 24
输出：5
*/

/* 思路：
动态规划   以4 24为例 
1   2   3   4   5   6   7   8   9   10   11   12   13   14   15   16   17   18   19   20   21   22   23   24
0   0   0   0   0   1-4     2-6 2-6 3-8       3-8            4-10           4-12                          5-18
                                              3-9
                                              4-10
*/

#include <iostream>
#include <limits.h>
#include <math.h>
#include <vector>
using namespace std;
void get_div_num(int v, vector<int> &a) {
    for (int i = 2; i <= sqrt(v); i++) {
        if (v % i == 0) {
            a.push_back(i);
            //通过一次性找到一个约数的同时找到它的对称约数，将两个约数同时添加到vector a中。
            //对于一个约数i，如果v可以被i整除，那么v/i也是一个约数。因此，我们可以在循环中同时处理i和v/i，从2迭代到 sqrt(v)，而不仅仅是迭代到sqrt(v)的一半。如果i和v/i相等，我们只需要添加其中一个，因为它们是相同的。
            if (v / i != i) {
                a.push_back(v / i);
            }
        }
    }
}

int jump(int n, int m) {
    //定义一个数组存放每个数最少需要多少步数,初始化为最大值，便于后面的判断
    vector<int> step(m + 1, INT_MAX);//INT_MAX表示不可到达的数,需要多创建一个,数组从0开始,映射到m个需要m+1
    step[n] = 0;                     //当前位置为n,初始化n为0

    for (int i = n; i <= m; i++) {
        if (step[i] == INT_MAX) {
            continue;
        }

        vector<int> a;//用于保存约数
        get_div_num(i, a);
        for (int j = 0; j < a.size(); j++) {
            // step[a[j] + i] != INT_MAX 说明该位置已经被跳过，有步数记录,找最小的
            if (a[j] + i <= m && step[i + a[j]] != INT_MAX) {
                //挑选最小的,当前所在位置+1步数和当前跳过约数的步数对比
                step[i + a[j]] = step[i + a[j]] < step[i] + 1 ? step[i + a[j]] : step[i] + 1;
            } else if (a[j] + i <= m) {
                step[i + a[j]] = step[i] + 1;
            }
        }
    }
    return step[m] == INT_MAX ? -1 : step[m];
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        cout << jump(n, m) << endl;
    }

    return 0;
}

//https://www.nowcoder.com/practice/4284c8f466814870bae7799a07d49ec8?tpId=85&&tqId=29852&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
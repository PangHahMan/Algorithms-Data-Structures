//https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387?
/* 
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶(n为正整数)总共有多少种跳法。
示例1
输入
3
输出
4

示例2
输入
1
输出
1

*/


/*思路：
每个台阶都有跳与不跳两种情况（除了最后一个台阶），最后一个台阶必须跳。所以共用2^(n-1)种情况
根据题图解析可以得出有一阶的时候 f(1) = 1 ； 有两阶的时候可以有 f(2) = 1+f(1)=2； 有三阶的时候可以有 f(3) =
1+f(2)+f(1)=4;
 ...
总跳法为: f(n) = 1+f(n-1) + f(n-2)+....+f(1) （第一个1是跳n阶只有一种方法）
依次类推，得到类推公式有n阶时：f(n)=2^(n-1)。
*/
class Solution {
public:
    int jumpFloorII(int number) {
        //2^(n-1) == 1 << (n-1)
        return 1 << (number - 1);
    }
};
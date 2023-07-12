/* 描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法（先后次序不同算不同的结果）。 
*/

/* 
示例1
输入：2
返回值：2

说明：青蛙要跳上两级台阶有两种跳法，分别是：先跳一级，再跳一级或者直接跳两级。因此答案为2       

示例2
输入：7
返回值：21 
*/

/*解题思路：
[定义状态] f(n)：青蛙跳上第n级台阶的总跳法数 
[状态递推] f(n) = f(n-1) + f(n-2)          
[初始状态] f(0) = 1（0台阶，就是起点，到达0台阶的方法有一种，就是不跳[这里可能有点奇怪，但是想想，如果方
法次数为0，就说明不可能开始...]）, f(1) = 1;


*/
//方法1 动态规划
class Solution {
public:
    int jumpFloor(int number) {
        //dp[n] = dp[n-1]+dp[n-2];
        int *dp = new int[number + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= number; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        int num = dp[number];//第number下标，就是第number阶台阶
        delete dp;
        return num;
    }
};

//方法二：
//在仔细看看这个代码，难道不像上题的斐波那契数列吗？
class Solution {
public:
    // 状态：f(n): 到第n阶台阶的总跳法，而到了n，只能是从n-1 or n-2跳过来的
    // 递推公式：所以f(n) = f(n-1) + f(n-2)
    // 初始值：f(1) = 1, f(2) = 2， 可以看成，从平地(0)开始跳到1台阶，方法1种。或者跳到2台阶，有两种方式
    int jumpFloor(int n) {
        int first = 1; //第一个台阶
        int second = 2;//第二个台阶
        int third = n; //等于n直接就考虑了f(1) = 1 && f(2) = 2的情况
        while (n > 2) {
            third = first + second;
            first = second;
            second = third;
            --n;
        }
        return third;
    }
};

//https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?
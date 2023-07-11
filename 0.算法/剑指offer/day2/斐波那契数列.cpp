/* 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
 
示例1
输入：4
返回值：3
说明：根据斐波那契数列的定义可知，fib(1)=1,fib(2)=1,fib(3)=fib(3-1)+fib(3-2)=2,fib(4)=fib(4-1)+fib(4-2)=3，所以答案为3。   

示例2
输入：1
返回值：1

示例3
输入：2
返回值：1
*/

/* 题目解析
斐波那契数列是 0 1 1 2 3 5 8 13 21 ...
解题方式很多，有递归方式，也有动归(迭代)方式，但是都是最简单的方式 
*/
#include <iostream>
#include <unordered_map>
using namespace std;
//迭代方案
class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1 || n == 2) {
            return 1;
        }
        int first = 1;
        int second = 1;
        int third = 1;
        for (int i = 3; i <= n; i++) {
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};

//递归方案
class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1 || n == 2) {
            return 1;
        }

        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};


//直接用最简单的方式因为代码空间复杂度过高，过不了OJ，所以我们可以采用map进行"剪枝"
class Solution {
private:
    unordered_map<int, int> filter;

public:
    int Fibonacci(int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1 || n == 2) {
            return 1;
        }

        int pre = 0;
        if (filter.find(n - 1) == filter.end()) {
            pre = Fibonacci(n - 1);
            filter.insert({n - 1, pre});
        } else {
            pre = filter[n - 1];
        }

        int ppre = 0;
        if (filter.find(n - 2) == filter.end()) {
            ppre = Fibonacci(n - 2);
            filter.insert({n - 2, ppre});
        } else {
            ppre = filter[n - 2];
        }
        return pre + ppre;
    }
};

//https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?
/* 描述
给定两个int A和B。编写一个函数返回A+B的值，但不得使用+或其他算数运算符。

测试样例：
1,2
返回：3 
*/

/* 思路： 
两个数字相加：
求取数字相加后当前二进制位的取值(不考虑进位)
求取数字相加后进位的数值

1+3
0001
0011

相加后二进制位的取值不考虑进位：0010  这个值可以通过异或求得
相加后进位的数据：0010  这个值可以按位与左移一位取得

0010
0010
继续异或在按位左移1,其中一个为0，则另外一个就是结果
相加后二进制位的取值不考虑进位：0000   ：异或   
相加后进位的数据：0100 ：按位与左移    

0000
0100
a 异或  0100
b 按位左移  0000   

*/
//递归：思路就是其中一个为0，那么剩下来就是相加的值，也就是说一个是不是进位的，一个是进位的，两个相加就是值，直到算到没有进位为止。
class UnusualAdd {
public:
    int addAB(int A, int B) {
        if (A == 0) {
            return B;
        }

        if (B == 0) {
            return A;
        }

        int a = A ^ B;       //相加不考虑进位的值通过异或求得
        int b = (A & B) << 1;//考虑进位的值通过按位与左移1位得出

        return addAB(a, b);
    }
};


//迭代1
class UnusualAdd {
public:
    int addAB(int A, int B) {
        int a = A ^ B;       //相加不考虑进位的值通过异或求得,异或就是没有进位的加法
        int b = (A & B) << 1;//考虑进位的值通过按位与左移1位得出

        //b不等于0,其实就表示没有进位了,而a就是a^b异或得来,没有进位说明可以返回结果了
        while (b != 0) {
            int tmp = a ^ b;
            b = (a & b) << 1;
            a = tmp;
        }

        return a;
    }
};


//https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId=8&&tqId=11065&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
/* 描述
给定两个32位整数n和m，同时给定i和j，将m的二进制数位插入到n的二进制的第j到第i位,保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1，其中二进制的位数从0开始由低到高。



测试样例：
1024，19，2，6
返回：1100 
*/
/* 
m:1024：100000000 00 n:19 ： 10011 要把n的二进制值插入m的第j位到第i位，只需要把n先左移j位，然后再进行或运算（|）即可。
m: 10000000000
n: 00001001100   n左移j位，j位2，左移2位
   10001001100 */

/* 思路：
这个描述非常的不清晰，主要意思 给定两个32位整数n和m，以及两个位置索引i和j。要求将整数m的二进制数位插入到整数n的二进制的第j到第i位（从右往左，从低位到高位的数位位置）。其中，假设n的第j到第i位均为0，并且m的二进制位数小于等于i-j+1。

该问题可以通过进行位运算来解决。具体思路如下：
左移m：
将整数m左移j位，目的是将m中的二进制数位移动到对应的位置上。

按位或运算：
将左移后的m与n进行按位或运算，将m中的二进制数位插入到n的对应位置上。
按位或运算会将两个数对应位上的值进行合并，如果对应位上的值有一个为1，则结果对应位上的值也为1；如果对应位上的值都为0，则结果对应位上的值也为0。

返回结果：
返回按位或运算后的结果，即为最终的插入结果。
 */
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        return n | (m << j);
    }
};

//https://www.nowcoder.com/practice/30c1674ad5694b3f8f0bc2de6f005490?tpId=8&&tqId=11019&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
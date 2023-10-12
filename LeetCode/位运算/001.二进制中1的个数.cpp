/* 描述
输入一个整数 n ，输出该数32位二进制表示中1的个数。其中负数用补码表示。 
示例1
输入：1复制
返回值：2
说明：十进制中10的32位二进制表示为0000 0000 0000 0000 0000 0000 0000 1010，其中有两个1。       

示例2
输入：-1
返回值：32
说明：负数使用补码表示 ，-1的32位二进制表示为1111 1111 1111 1111 1111 1111 1111 1111，其中32个1    
*/

//方法1
class Solution {
public:
    int NumberOf1(int n) {
        int i = 0;
        int count = 0;
        for (i = 0; i < 32; i++) {
            if ((n >> i) & 1)
                count++;
        }
        return count;
    }
};

//方法2 逆序取余法  这种方法负数要当成无符号整数
class Solution {
public:
    int NumberOf1(int n) {
        int i = 0;
        int count = 0;
        while (n) {
            if (n % 2)
                count++;
            n /= 2;
        }
        return count;
    }
};


//方法3 优化  效率最高
/*
n=11
n = n&(n-1)
1011 == n
1010 == n-1
1011&1010==1010

1010 == n
1001 == n-1
1010&1001==1000

1000 == n
0111 == n-1
1000&0111==0000   按位与到0为止，一共三次，说明就有3个1
*/

class Solution {
public:
    int NumberOf1(int n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};

//https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?
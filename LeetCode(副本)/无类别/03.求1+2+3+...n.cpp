/* 描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。 
*/


class Solution {
public:
    class Sum {
    public:
        Sum() {
            sum += i;
            i++;
        }
    };
    int Sum_Solution(int n) {
        Sum *a = new Sum[n];//调用Sum的构造函数n次
        return sum;
    }

private:
    static int i;
    static int sum;
};

int Solution::i = 1;
int Solution::sum = 0;